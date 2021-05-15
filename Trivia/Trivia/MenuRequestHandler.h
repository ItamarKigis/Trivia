#include "IRequestHandler.h"
class MenuRequestHandler : public IRequestHandler
{
public:
	bool isRequestRelevant(RequestInfo request) { return true; };
	RequestResult handleRequest(RequestInfo request) { return RequestResult(); };
};