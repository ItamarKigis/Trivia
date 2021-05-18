#include "Server.h"

Server::Server(RequestHandlerFactory& handler, IDataBase& DB) : m_handlerFactory(handler),
m_database(&DB)
{
	m_communicator = new Communicator(handler);
}

void Server::run()
{
	m_communicator->startCommunicator();
}