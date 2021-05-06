#pragma once
#include "IRequestHandler.h"
#define LOGIN_CODE 200
class LoginRequestHandler : public IRequestHandler
{
public:
	bool isRequestRelevant(RequestInfo request);
	RequestResult handleRequest(RequestInfo request);
};
