#include "LoginRequestHandler.h"
#include "JsonRequestPacketDeserializer.h"
#include "RequestHandlerFactory.h"
#include <WinSock2.h>
#include <Windows.h>
#include <map>
#include <thread>
#include <mutex>
#define MAX_LEN 4096
#define PORT 8989

class Communicator
{
public:
	Communicator(RequestHandlerFactory& handler);
	~Communicator();
	void startHandleRequests();
	void startCommunicator();	//function that starts bindAndListen, vecause it is a private function
private:
	void bindAndListen();

	//input: socket to the client, requests from the client
	//output: responses to the client
	//Function manages the conncetion and the converation with the client.
	void handleNewClient(SOCKET);

	//Function Gets commands from the user in the console application, if the command is "EXIT" - change the exit varaible so the program will end 
	void checkExit();
	SOCKET _serverSocket;
	std::map<SOCKET, IRequestHandler*> m_clients;
	bool exit;
	std::mutex _clientsMutex;
	std::unique_lock<std::mutex> _clientsLocker;
	RequestHandlerFactory& m_handlerFactory;
};
