#include <ctime>
#include <vector>
class IRequestHandler
{
public:
	virtual bool isRequestRelevant(RequestInfo request) = 0;
	virtual RequestResult handleRequest(RequestInfo request) = 0;
};
struct RequestResult
{
public:
	std::vector<unsigned char>response;
	IRequestHandler* newHandler;
};

struct RequestInfo
{
public:
	int RequestId;
	time_t recivaltime;
	std::vector<unsigned char>buffer;
};