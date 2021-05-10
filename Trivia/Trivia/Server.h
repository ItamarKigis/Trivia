#pragma once
#include "Communicator.h"
#include "IDataBase.h"
class Server
{
public:
	void run();
private:
	Communicator m_communicator;
	IDataBase* m_database;
};
