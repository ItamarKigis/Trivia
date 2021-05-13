#pragma once
#ifndef REQUESTHANDLERFACTORY_H
#define REQUESTHANDLERFACTORY_H

#include "LoginRequestHandler.h"
#include "LoginManager.h"
class LoginRequestHandler;
class LoginManager;
class RequestHandlerFactory
{
public:
	LoginRequestHandler* createLoginRequestHandler();
	LoginManager& getLoginManager();
private:
	LoginManager m_loginManager;
};
#endif