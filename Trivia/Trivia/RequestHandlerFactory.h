#pragma once

#include "LoginRequestHandler.h"
#include "LoginManager.h"
class LoginRequestHandler;
class LoginManager;
class RequestHandlerFactory
{
public:
	LoginRequestHandler* createLoginRequestHandler();
	LoginManager& getLoginManager();
	RequestHandlerFactory(LoginManager& manager, IDataBase& DB);
private:
	LoginManager m_loginManager;
	IDataBase* m_dataBase;
};