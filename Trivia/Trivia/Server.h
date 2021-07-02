#pragma once
#include "Communicator.h"
#include "IDataBase.h"
class Server
{
public:
	void run();
	Server(RequestHandlerFactory& handler, IDataBase& DB);
	~Server();
private:
	Communicator* m_communicator;
	RequestHandlerFactory m_handlerFactory;
	IDataBase* m_database;
};
