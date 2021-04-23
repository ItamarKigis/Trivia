#pragma once

#include <WinSock2.h>
#include <Windows.h>
#include <thread>
#include <set>
#include <mutex>
#include <queue>
#include <fstream>
#include "Helper.h"
#include "LoginRequestHandler.h"
#define MAX_LEN 150
#define ZERO 0
#define THIRD_INDEX 2
#define ASCI_OF_ZERO 48
#define TEN 10
#define LEN_OF_USERNAMES 5
#define ONE 1
class Server
{
public:
	Server();
	~Server();
	void serve(int port);

private:

	void accept();
	void clientHandler(SOCKET clientSocket);
	void checkExit();
	std::string getAllUsernames();

	SOCKET _serverSocket;
	
	bool exit;
};
