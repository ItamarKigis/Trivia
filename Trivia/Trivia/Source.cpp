#pragma comment (lib, "ws2_32.lib")

#include "WSAInitializer.h"
#include "Server.h"
#include <iostream>
#include <exception>
#include "Helper.h"
int main()
{
	int port = 8989;
	try
	{
		WSAInitializer wsaInit;
		Server myServer;

		myServer.serve(port);
	}
	catch (std::exception& e)
	{
		std::cout << "Error occured: " << e.what() << std::endl;
	}
	system("PAUSE");
	return 0;
}