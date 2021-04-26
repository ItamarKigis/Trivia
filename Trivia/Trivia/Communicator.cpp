#include "Communicator.h"
#include <exception>
#include <iostream>
#include <string>

Communicator::Communicator()
{

	// this server use TCP. that why SOCK_STREAM & IPPROTO_TCP
	// if the server use UDP we will use: SOCK_DGRAM & IPPROTO_UDP
	exit = false;
	_serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (_serverSocket == INVALID_SOCKET)
		throw std::exception(__FUNCTION__ " - socket");
}

Communicator::~Communicator()
{
	try
	{
		for (std::map<SOCKET, IRequestHandler*>::iterator it = m_clients.begin(); it != m_clients.end(); it++)
		{
			delete it->second; // wanted use smart pointers, probably use later
		}
		// the only use of the destructor should be for freeing 
		// resources that was allocated in the constructor
		closesocket(_serverSocket);
	}
	catch (...) {}
}

void Communicator::startCommunicator()
{
	bindAndListen();
}

void Communicator::bindAndListen()
{

	struct sockaddr_in sa = { 0 };

	sa.sin_port = htons(PORT); // port that server will listen for
	sa.sin_family = AF_INET;   // must be AF_INET
	sa.sin_addr.s_addr = INADDR_ANY;    // when there are few ip's for the machine. We will use always "INADDR_ANY"

	// again stepping out to the global namespace
	// Connects between the socket and the configuration (port and etc..)
	if (bind(_serverSocket, (struct sockaddr*)&sa, sizeof(sa)) == SOCKET_ERROR)
		throw std::exception(__FUNCTION__ " - bind");

	// Start listening for incoming requests of clients
	if (listen(_serverSocket, SOMAXCONN) == SOCKET_ERROR)
		throw std::exception(__FUNCTION__ " - listen");
	std::cout << "Listening on port " << 8989 << std::endl;
	//this thread will get the commands from the console and checks if the program should exit.
	std::thread t(&Communicator::checkExit, this);
	t.detach();

	while (!exit)
	{
		// the main thread is only accepting clients 
		// and add then to the list of handlers
		std::cout << "Waiting for client connection request" << std::endl;
		startHandleRequests();
	}
}

void Communicator::startHandleRequests()
{
	// notice that we step out to the global namespace
	// for the resolution of the function accept

	// this accepts the client and create a specific socket from server to this client

	SOCKET client_socket = ::accept(_serverSocket, NULL, NULL);

	if (client_socket == INVALID_SOCKET && exit != true)
		throw std::exception(__FUNCTION__);
	else if (!exit)
	{
		std::cout << "Client accepted. Server and client can speak" << std::endl;

		m_clients[client_socket] = new LoginRequestHandler();

		// the function that handle the conversation with the client
		std::thread t(&Communicator::handleNewClient, this, client_socket);
		t.detach();
	}
}

void Communicator::handleNewClient(SOCKET clientSocket)
{
	try
	{
		char m[MAX_LEN] = { 0 };
		std::string MsgToClient = "Hello";
		send(clientSocket, MsgToClient.c_str(), MsgToClient.size(), 0);
		recv(clientSocket, m, MAX_LEN - 1, 0);
		std::string MsgFromClient(m);
		std::cout << "Client sended " << MsgFromClient << std::endl;
	}
	catch (...)
	{
		closesocket(clientSocket);
	}
}

void Communicator::checkExit()
{
	std::string input = "";
	while (input != "EXIT")
	{
		std::cin >> input;
	}
	closesocket(_serverSocket);
	exit = true;
}
