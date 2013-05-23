]// blah blah
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>

#include <map>

#define DEFAULT_PORT "7777"
#define DEFAULT_BUFLEN 512
#define CHUNK_SIZE 10

enum Event
{
	EVENT_NETWORKREAD = 1
	EVENT_NETWORKWRITE = 2
};

// TODO: Make sure this matches the Wrapper Facade pattern by the letter
// WinSocks, taken from MSDN
class ComuunicationWrapper
{
public:
	ComuunicationWrapper()
		: m_listenSocket(INVALID_SOCKET), m_clientSocket(INVALID_SOCKET) {}

	int Init()
	{
		int iResult;

		// Initialize Winsock
		iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
		if (iResult != 0)
		{
			printf("WSAStartup failed: %d\n", iResult);
			return 1;
		}

		struct addrinfo* result = NULL;
		struct addrinfo* ptr = NULL;
		struct addrinfo hints;

		ZeroMemory(&hints, sizeof (hints));
		hints.ai_family = AF_INET;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_protocol = IPPROTO_TCP;
		hints.ai_flags = AI_PASSIVE;

		// Resolve the local address and port to be used by the server
		iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
		if (iResult != 0)
		{
			printf("getaddrinfo failed: %d\n", iResult);
			WSACleanup();
			return 1;
		}
		
		// Create a SOCKET for the server to listen for client connections
		m_listenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);

		if (m_listenSocket == INVALID_SOCKET)
		{
			printf("Error at socket(): %ld\n", WSAGetLastError());
			freeaddrinfo(result);
			WSACleanup();
			return 1;
		}

		// Setup the TCP listening socket
		iResult = bind( m_listenSocket, result->ai_addr, (int)result->ai_addrlen);
		if (iResult == SOCKET_ERROR)
		{
			printf("bind failed with error: %d\n", WSAGetLastError());
			freeaddrinfo(result);
			closesocket(m_listenSocket);
			WSACleanup();
			return 1;
		}

		// Once the bind function is called, the address information returned by the getaddrinfo function is no longer needed.
		freeaddrinfo(result);

		// Listen
		if ( listen( m_listenSocket, SOMAXCONN ) == SOCKET_ERROR )
		{
			printf( "Listen failed with error: %ld\n", WSAGetLastError() );
			closesocket(m_listenSocket);
			WSACleanup();
			return 1;
		}
		return 0;
	}

	int Accept()
	{
		// Accept a client socket
		m_clientSocket = accept(m_listenSocket, NULL, NULL);
		if (m_clientSocket == INVALID_SOCKET)
		{
			printf("accept failed: %d\n", WSAGetLastError());
			closesocket(m_listenSocket);
			WSACleanup();
			return 1;
		}
		return 0;
	}

	int Recv(char *recvbuf, int recvbuflen)
	{
		int iResult = 0;
		int bytesReceived = 0;

		// Receive one "chunk"
		do
		{
			char buffer[DEFAULT_BUFLEN];
			iResult = recv(m_clientSocket, buffer, sizeof(buffer), 0);
			if (iResult > 0)
			{
				printf("Bytes received: %d\n", iResult);

				// concat our data received
				for (int i=0; i<iResult; ++i)
				{
					recvbuf[bytesReceived+i] = buffer[i];
				}
				bytesReceived += iResult;
			} 
			else if (iResult == 0)
			{
				printf("Connection closing...\n");
			}
			else
			{
				printf("recv failed: %d\n", WSAGetLastError());
				closesocket(m_clientSocket);
				WSACleanup();
				return 1;
			}
		} while (iResult != 0 && bytesReceived < CHUNK_SIZE);
		recvbuf[bytesReceived] = 0; // null terminate the string
		return 0;
	}

	int Send(const char* sendbuff, int amount)
	{
		int iSendResult;

		iSendResult = send(m_clientSocket, sendbuff, amount, 0);
		if (iSendResult == SOCKET_ERROR)
		{
			printf("send failed: %d\n", WSAGetLastError());
			closesocket(m_clientSocket);
			WSACleanup();
			return 1;
		}
		printf("Bytes sent: %d\n", iSendResult);
		return 0;
	}

private:
	WSADATA wsaData;
	SOCKET m_listenSocket;
	SOCKET m_clientSocket;
};

class IEventHandler
{
public:
	virtual void HandleEvent() = 0;
	virtual void GetRawHandle() = 0; // what is this for again?
};

class EchoServiceHandler : public IEventHandler
{
};

class EchoServiceAcceptor : public IEventHandler
{
public:
	virtual ~EchoServiceAcceptor() {}

	virtual void HandleEvent()
	{
	}

	virtual void GetRawHandle()
	{
	}
private:
	ComuunicationWrapper& m_comm;
};

class EchoServerReactor
{
public:
	EchoServerReactor(ComuunicationWrapper& comm) : m_comm(comm) {}

	void RegisterHandler(IEventHandler* handler, Event type)
	{
		// TODO: Handle overwriting existing entry
		m_handlers[type] = handler;
	}
	
	void UnregisterHandler(Event type)
	{
		m_handlers.erase(type);
	}

	void HandleEvents()
	{
		// Block until we receive data from the socket
		switch (SelectOne())
		{
		case EVENT_ECHO:

			break;
		default:
			break;
		}
	}

private:
	Event SelectOne()
	{
		m_comm.Accept();

		// normally this would switch on the socket input for a certain cmd
		// however in this simple system, we only handle one type of event
		return EVENT_ECHO;
	}

	ComuunicationWrapper& m_comm;

	std::map<Event, IEventHandler*> m_handlers;
};

int FindNullTerminator(const char* buffer, int maxlength)
{	
	for (int i=0; i<maxlength; ++i)
	{
		if (buffer[i] == 0)
			return i;
	}
	return maxlength;
}

int main()
{
	ComuunicationWrapper commWrapper; 
	if (commWrapper.Init())
	{
		EchoServiceAcceptor echoServiceAcceptor;

		EchoServerReactor reactor(commWrapper);
		reactor.RegisterHandler(&echoServiceAcceptor);

		for (;;)
		{
			reactor.HandleEvents();
		}

		reactor.UnregisterHandler(&echoServiceAcceptor);
	}

	return 0;
}