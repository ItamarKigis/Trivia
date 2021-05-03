#include "LoginRequestHandler.h"

bool LoginRequestHandler::isRequestRelevant(RequestInfo request)
{
    return request.RequestId == LOGIN;
}

RequestResult LoginRequestHandler::handleRequest(RequestInfo request)
{
    if (isRequestRelevant(request)) 
    {
        //for now we reutrn a struct with empty fields.
        RequestResult result;
        result.newHandler = nullptr;
        return result;
    }
    //also here we return a struct without a fields for now.
    return RequestResult();
}
