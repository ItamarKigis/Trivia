#pragma once

#include <deque>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <WinSock2.h>
#include "RecvMessage.h"
#include "Helper.h"

#if defined NDEBUG
#define TRACE( format, ... )
#else
#define TRACE( format, ... )   printf( "%s::%s(%d)" format, __FILE__, __FUNCTION__,  __LINE__, __VA_ARGS__ )
#endif


// Q: why do we need this class ?
// A: this is the main class which holds all the resources,
// accept new clients and handle them.
class server
{
public:
	server();
	~server();
	void serve();


private:
	void bindAndListen();
	void acceptClient();
	void clientHandler(SOCKET client_socket);
	void safeDeleteUser(SOCKET id);

	void handleReceivedMessages();
	std::string getCurrentUser();
	std::string getNextUser();
	std::string get_user_name(SOCKET id);
	void addReceivedMessage(RecvMessage*);
	static RecvMessage* build_receive_message(SOCKET client_socket, int msg_code);
	std::string getAllUsernames();
		
	SOCKET _socket;

	// Queue for all clients. This way we will know who's the current writer.
	// SOCKET: client socket
	// string: userName
	std::deque<pair<SOCKET, string>> _clients;


	// Queue for messages - Will hold the mssage code and the file data. To add messages use std::ref<const ClientSocket>
	// SOCKET: client socket
	// string: message
	std::queue<RecvMessage*> _messageHandler;

	std::mutex _mtxReceivedMessages;
	std::condition_variable _msgQueueCondition;
};

