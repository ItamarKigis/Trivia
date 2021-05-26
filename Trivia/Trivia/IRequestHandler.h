#pragma once
#include <ctime>
#include <vector>
#include "Serializer.h"
#include "JsonRequestPacketDeserializer.h"
class IRequestHandler;
typedef struct RequestResult
{
	std::vector<unsigned char>response;
	IRequestHandler* newHandler;
}RequestResult;

typedef struct RequestInfo
{
	int RequestId;
	time_t recivaltime;
	std::vector<unsigned char>buffer;
}RequestInfo;
class IRequestHandler
{
public:
	virtual ~IRequestHandler() = default;
	IRequestHandler() = default;
	virtual bool isRequestRelevant(RequestInfo request) const = 0;
	virtual RequestResult handleRequest(RequestInfo request) = 0;
};
