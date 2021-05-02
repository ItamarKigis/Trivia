#include "IRequestHandler.h"
#define LOGIN 200
class LoginRequestHandler : public IRequestHandler
{
public:
	bool isRequestRelevant(RequestInfo request);
	RequestResult handleRequest(RequestInfo request);
};