#pragma once
#include "IRequestHandler.h"
#include <memory>
#include "RequestHandlerFactory.h"
#include "MenuRequestHandler.h"
class RequestHandlerFactory;
class LoginManager;
class LoginRequestHandler : public IRequestHandler
{
public:
	LoginRequestHandler(LoginManager& loginManager, RequestHandlerFactory& handlerFactory);
	bool isRequestRelevant(const RequestInfo request) const override;
	RequestResult handleRequest(const RequestInfo request) override;
private:
	LoginManager& m_loginManager;
	RequestHandlerFactory& m_handlerFactory;

	RequestResult login(const RequestInfo request);
	RequestResult signup(const RequestInfo request);
};