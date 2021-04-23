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

class Communicator
{
public:
	Communicator();
	~Communicator();
	void startHandleRequests();
	void startCommunicator();
private:
	void bindAndListen();
	void handleNewClient(SOCKET);
	void checkExit();

	SOCKET _serverSocket;
	std::map<SOCKET, IRequestHandler*> m_clients;
	bool exit;
};