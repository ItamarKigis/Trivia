#include "LoginRequestHandler.h"

bool LoginRequestHandler::isRequestRelevant(RequestInfo request)
{
    return request.RequestId == LOGIN_CODE;
}

RequestResult LoginRequestHandler::handleRequest(RequestInfo request)
{
    JsonResponsePacketSerializer* serializer = new JsonResponsePacketSerializer();
    JsonRequestPacketDeserializer* deserializer = new JsonRequestPacketDeserializer();
    RequestResult result;
    std::vector<unsigned char> response;
    if (isRequestRelevant(request)) //LOGIN
    {
        //deserialize the request
        LoginRequest loginStruct =  deserializer->deserializeLoginRequest(request.buffer);
        //build response
        LoginResponse login = { LOGIN_CODE };
        response = serializer->serializeResponse(login);
    }
    else if (request.RequestId == int(CODES::SIGN_UP))//SIGN UP
    {
        //deserialize the request
        SignupRequest signUpStruct = deserializer->deserializeSignupRequest(request.buffer);
        //build response
        SignupResponse signUp = { int(CODES::SIGN_UP) };
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
