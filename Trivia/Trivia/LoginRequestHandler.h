#pragma once
#ifndef LOGINREQUESTHANDLER_H
#define LOGINREQUESTHANDLER_H

#include "IRequestHandler.h"
#include <memory>
#include "RequestHandlerFactory.h"
class RequestHandlerFactory;
class LoginManager;
class LoginRequestHandler : public IRequestHandler
{
public:
	LoginRequestHandler(LoginManager& loginManager, RequestHandlerFactory& handlerFactory);
	bool isRequestRelevant(RequestInfo request);
	RequestResult handleRequest(RequestInfo request);
private:
	LoginManager& m_loginManager;
	RequestHandlerFactory& m_handlerFactory;

	RequestResult login(RequestInfo request);
	RequestResult signup(RequestInfo request);
};
#endif