#include "LoginRequestHandler.h"

bool LoginRequestHandler::isRequestRelevant(RequestInfo request)
{
    return request.RequestId == LOGIN_CODE;
}

RequestResult LoginRequestHandler::handleRequest(RequestInfo request)
{
    JsonResponsePacketSerializer* serializer = new JsonResponsePacketSerializer();
    RequestResult result;
    std::vector<unsigned char> response;
    if (isRequestRelevant(request)) //LOGIN
    {
        LoginResponse login = { 200 };
        response = serializer->serializeResponse(login);
    }
    else if (request.RequestId == int(CODES::SIGN_UP))//SIGN UP
    {
        SignupResponse signUp = { 210 };
        response = serializer->serializeResponse(signUp);
    }
    else
    {
        ErrorResponse error = { "message" };
        response = serializer->serializeResponse(error);
    }
    result.newHandler = nullptr;
    result.response = response;
    return result;
}
