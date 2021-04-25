#include "LoginRequestHandler.h"
#include <WinSock2.h>
#include <Windows.h>
#include <map>
#include <thread>
#define MAX_LEN 150
#define ZERO 0
#define THIRD_INDEX 2
#define ASCI_OF_ZERO 48
#define TEN 10
#define LEN_OF_USERNAMES 5
#define ONE 1
#define PORT 8989

class Communicator
{
public:
	Communicator();
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
};