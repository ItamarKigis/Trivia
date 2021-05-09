#pragma once
#include "IRequestHandler.h"
#include <memory>
class LoginRequestHandler : public IRequestHandler
{
public:
	bool isRequestRelevant(RequestInfo request);
	RequestResult handleRequest(RequestInfo request);
};
