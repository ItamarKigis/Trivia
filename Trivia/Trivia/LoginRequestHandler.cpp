#include "LoginRequestHandler.h"

bool LoginRequestHandler::isRequestRelevant(RequestInfo request)
{
    return request.RequestId == int(CODES::LOGIN);
}

RequestResult LoginRequestHandler::handleRequest(RequestInfo request)
{
    std::unique_ptr<JsonResponsePacketSerializer> serializer = std::make_unique<JsonResponsePacketSerializer>();
    std::unique_ptr<JsonRequestPacketDeserializer> deserializer = std::make_unique<JsonRequestPacketDeserializer>();
    RequestResult result;
    std::vector<unsigned char> response;
    if (isRequestRelevant(request)) //LOGIN
    {
        //deserialize the request
        LoginRequest loginStruct = deserializer->deserializeLoginRequest(request.buffer);
        //build response
        LoginResponse login = { int(CODES::LOGIN) };
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
