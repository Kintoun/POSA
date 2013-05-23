//
// Built with ACE 6.1.8 in VS 2012
// Wrapper Facade would be ACE Socket Streams
// Reactor is of course Ace Reactor
// Acceptor is of course Ace Acceptor with Ace Service Handler
//#define ACE_USES_WCHAR
#include <ACE/Acceptor.h>
#include <ACE/Svc_Handler.h>
#include <ACE/SOCK_Stream.h>
#include <ACE/SOCK_Acceptor.h>

#define DEFAULT_PORT 7777
#define DEFAULT_CHUNK_SIZE 10

class EchoServerHandler : public ACE_Svc_Handler<ACE_SOCK_Stream, ACE_NULL_SYNCH>
{
public:
	virtual int handle_input(ACE_HANDLE /*handle*/)
	{
		char buffer[DEFAULT_CHUNK_SIZE];
		size_t bytesRead;
		size_t bytesSent;

		ACE_Time_Value time(60); // timeout after 1min of no input

		// recv from client
		if (peer().recv_n(buffer, sizeof(buffer), 0, &time, &bytesRead) <= 0)
			return -1;
		
		// echo back to client
		if (peer().send_n(buffer, bytesRead, 0, &time, &bytesSent) <= 0)
			return -1;

		return 0;
	}
};

int main(int argc, char* argv[])
{
	ACE_Reactor reactor;
	ACE_Acceptor<EchoServerHandler, ACE_SOCK_Acceptor> echoServerAcceptor;

	if (echoServerAcceptor.open(ACE_INET_Addr(DEFAULT_PORT), &reactor) == -1)
		return 1;

	reactor.run_reactor_event_loop();

	return 0;
}