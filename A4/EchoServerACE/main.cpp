// Echos 1 "chunk" which is 10 characters per connection.
// Built with ACE 6.1.8 in VS 2012
#include <assert.h>
#include "ace/Acceptor.h"
#include "ace/Svc_Handler.h"
#include "ace/SOCK_Acceptor.h"
#include "ace/SOCK_Stream.h"

#define DEFAULT_PORT 7777
// Amount of time to wait for the client to send data.
#define TIMEOUT_SECS 30
#define DEFAULT_CHUNK_SIZE 10

// Stores a string version of the current thread id into buffer and
// returns the size of this thread id in bytes.
ssize_t ACE_OS_thr_id(char buffer[], size_t buffer_length)
{
#if defined (ACE_WIN32)
  return ACE_OS::sprintf (buffer,
                          "Thread id: <%u>",
                          static_cast <unsigned> (ACE_Thread::self ()));
#else
  ACE_hthread_t t_id;
  ACE_OS::thr_self (t_id);
  return ACE_OS::sprintf (buffer,
                          "Thread id: <%lu>",
                          (unsigned long) t_id);
#endif /* WIN32 */
}

/**
 * @class Echo_Task
 *
 * @brief Contains a thread pool that dequeues client input from a
 * synchronized message queue and then echos the data received from
 * the client back to the client using blocking I/O.
 *
 * This class plays the Synchronous Layer and Queueing Layer role in
 * the Half-Sync/Half-Async pattern pattern.
 */
class Echo_Task : public ACE_Task<ACE_MT_SYNCH>
{
public:
	// Set the "high water mark" to 20000k.
	static const int HIGH_WATER_MARK = 1024 * 20000;
	static const int THREAD_POOL_SIZE = 4;

	// Default constructor sets the HIGH_WATER_MARK of the underlying
	// ACE_Message_Queue.
	Echo_Task()
	{
		// Set the high water mark, which limits the amount of data
		// that will be used to buffer client input pending succesfully
		// echoing back to the client.
		msg_queue()->high_water_mark(HIGH_WATER_MARK);
		activate(THR_BOUND, THREAD_POOL_SIZE);
	}

	// This hook method runs in each thread of control in the thread pool.
	virtual int svc();

	// Enqueue the client_input in the ACE_Message_Queue.
	virtual int put(ACE_Message_Block* client_input, ACE_Time_Value* timeout = 0)
	{
		return putq(client_input, timeout);
	}
};

/**
 * @class Echo_Svc_Handler
 *
 * @brief Echos data received from the client back to the client using
 * nonblocking I/O.
 *
 * This class plays the concrete event handler role in the Reactor
 * pattern and the service handler role in the Acceptor/Connector
 * pattern.
 */
class Echo_Svc_Handler : public ACE_Svc_Handler<ACE_SOCK_Stream, ACE_NULL_SYNCH>
{
public:
  // This constructor takes a default parameter of 0 so that it will
  // work properly with the make_svc_handler() method in the
  // Echo_Acceptor.
	Echo_Svc_Handler(Echo_Task* echo_task = 0) : echo_task_(echo_task), client_input_(0)
	{
	}

	// Hook method called by the ACE_Acceptor to activate the service handler.
	virtual int open(void* acceptor)
	{
		ACE_Svc_Handler::open(acceptor);
		if (reactor() 
			&& reactor()->register_handler(this, ACE_Event_Handler::READ_MASK) != -1
			&& reactor()->schedule_timer(this, 0, ACE_Time_Value(TIMEOUT_SECS)) != -1)
		{
			return 0;
		}
		return -1;
	}

	// Close down the event handler.
	virtual int handle_close(ACE_HANDLE h, ACE_Reactor_Mask m)
	{
		ACE_DEBUG((LM_DEBUG, ACE_TEXT("(%P|%t) closing the event handler\n")));
		return ACE_Svc_Handler<ACE_SOCK_Stream, ACE_NULL_SYNCH>::handle_close(h, m);
	}

	// This hook method is used to shutdown the service handler if the
	// client doesn't send data for several seconds.
	virtual int handle_timeout(ACE_Time_Value const&, void const*)
	{
		ACE_DEBUG((LM_DEBUG, ACE_TEXT("(%P|%t) timeout occurred, shutting down the event handler\n")));

		// Instruct the reactor to remove this service handler and shut it down.
		reactor()->remove_handler(this, ACE_Event_Handler::READ_MASK);
		return 0;
	}

	// This hook method is dispatched by the ACE Reactor when data shows
	// up from a client.
	virtual int handle_input(ACE_HANDLE /* handle */)
	{
		if (client_input_ == 0)
			client_input_ = new ACE_Message_Block(DEFAULT_CHUNK_SIZE);

		if (recv(client_input_) == -1)
			ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("(%P|%t) handle_input failed\n")),	-1);
		
		reactor()->remove_handler(this, ACE_Event_Handler::READ_MASK);
		reactor()->cancel_timer(this);
		echo_task_->put(new ACE_Message_Block(reinterpret_cast<char*>(this)), &ACE_Time_Value(TIMEOUT_SECS));
		return 0;
	}

	// Receive the next chunk of data from the client.
	int recv(ACE_Message_Block *&client_input)
	{
		// recv from client
		if (peer().recv_n(client_input->wr_ptr(), client_input->size(), 0, &ACE_Time_Value(TIMEOUT_SECS)) <= 0)
			return -1;

		return 0;
	}

	// Reschedule the connection timer.
	int reschedule_timer(void)
	{
		// Cancel the existing timer..
		if(reactor()->cancel_timer(this) == -1)
		{
			ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("(%P|%t) cancel_timer failed\n")),	-1);
		}
		// .. and reschdule it for TIMEOUT_SECS.
		else if(reactor()->schedule_timer(this, 0, ACE_Time_Value(TIMEOUT_SECS)) == -1)
		{
			ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("(%P|%t) schedule_timer failed\n")), -1);
		}
		else
		{
			return 0;
		}
	}

	// Contains the message fragment(s) received from the connected client.
	ACE_Message_Block *client_input_;

private:
	// Pointer to the thread pool that plays the role of the Half-Sync
	// layer in the Half-Sync/Half-Async pattern.
	Echo_Task *echo_task_;
};

/**
 * @class Echo_Acceptor
 *
 * @brief A factory that accepts connections and creates/activates
 * Echo_Svc_Handlers to process data on the connections.
 *
 * This class plays the role of the concrete acceptor role in the
 * Acceptor/Connector pattern.  The ACE_SOCK_Acceptor plays role of
 * the wrapper facade in the Wrapper Facade pattern.
 */
class Echo_Acceptor : public ACE_Acceptor<Echo_Svc_Handler, ACE_SOCK_Acceptor> 
{
public: 
	virtual int open(ACE_INET_Addr addr, ACE_Reactor* r)
	{
		ACE_Acceptor::open(addr,r);
		if (reactor()->register_handler(this, ACE_Event_Handler::ACCEPT_MASK) == -1)
			return -1;
		return 0;
	}

protected:
	// A factory method that creates a new Echo_Svc_Handler instance and
	// associates the Echo_Task thread pool with it.
	virtual int make_svc_handler(Echo_Svc_Handler *&sh)
	{
		if (sh == 0)
		{
			ACE_DEBUG((LM_DEBUG, ACE_TEXT("(%P|%t) make_svc_handler called\n")));

			ACE_NEW_RETURN(sh, Echo_Svc_Handler(&echo_task_), -1);
			sh->reactor(reactor());
		}
		return 0;
	}

private:
	// Thread pool (Half-Sync/Half-Async pattern)
	Echo_Task echo_task_;
};

int Echo_Task::svc()
{
	for (ACE_Message_Block* msg; getq(msg) != -1; )
	{
		Echo_Svc_Handler* echo_svc_handler = reinterpret_cast<Echo_Svc_Handler*>(msg->rd_ptr());

		char threadId[256];
		size_t threadIdSize = ACE_OS_thr_id(threadId, sizeof(threadId));
		int error = echo_svc_handler->peer().send_n(threadId, threadIdSize);
		if (error <= 0)
			return error;

		char* sendMsg = echo_svc_handler->client_input_->data_block()->base();
		size_t sendSize = echo_svc_handler->client_input_->data_block()->size();
		error = echo_svc_handler->peer().send_n(sendMsg, sendSize);
		if (error <= 0)
			return error;
	}
	return 0;
}

int main(int argc, char* argv[])
{
	// Reactor
	ACE_Reactor reactor;

	// Acceptor-Connector.
	Echo_Acceptor echoAcceptor;

	if (echoAcceptor.open(ACE_INET_Addr(DEFAULT_PORT), &reactor) == -1)
		return 1;

	reactor.run_reactor_event_loop();

	return 0;
}