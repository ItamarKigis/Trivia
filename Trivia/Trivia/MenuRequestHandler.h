#include "IRequestHandler.h"
class MenuRequestHandler : public IRequestHandler
{
public:
	~MenuRequestHandler() override = default;
	bool isRequestRelevant(RequestInfo request) override { return true; };
	RequestResult handleRequest(RequestInfo request) override { return RequestResult(); };
};