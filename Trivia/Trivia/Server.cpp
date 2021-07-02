#include "Server.h"

Server::Server(RequestHandlerFactory& handler, IDataBase& DB) : m_handlerFactory(handler.getLoginManager(), DB, handler.getStatisticsManager()),
m_database(&DB)
{
	m_communicator = new Communicator(handler);
}

Server::~Server()
{
	delete(m_communicator);
}

void Server::run()
{
	m_communicator->startCommunicator();
}