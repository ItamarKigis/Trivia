#pragma once
#include "IRequestHandler.h"
#define LOGIN 200
class LoginRequestHandler : public IRequestHandler
{
public:
	LoginRequestHandler() { };
	bool isRequestRelevant(RequestInfo request);
	RequestResult handleRequest(RequestInfo request);
};