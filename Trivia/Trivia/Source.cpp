#pragma comment (lib, "ws2_32.lib")

#include "WSAInitializer.h"
#include "Server.h"
#include <iostream>
#include <exception>
#include "SqliteDatabase.h"
#include <bitset>
int main()
{
	try
	{
		WSAInitializer wsaInit;

		SqliteDatabase* dataBase = new SqliteDatabase("triviaDB.sqlite");
		LoginManager* manager = new LoginManager(dataBase);
		statisticsManager* statsManager = new statisticsManager(dataBase);
		RequestHandlerFactory* factoryHandler = new RequestHandlerFactory(*manager, *dataBase, *statsManager);
		Server myServer(*factoryHandler, *dataBase);

		myServer.run();

		delete(dataBase);
		delete(manager);
		delete(factoryHandler);
	}
	catch (std::exception& e)
	{
		std::cout << "Error occured: " << e.what() << std::endl;
	}
	system("PAUSE");
	return 0;
}