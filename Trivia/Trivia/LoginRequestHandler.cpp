#include "LoginRequestHandler.h"
LoginRequestHandler::LoginRequestHandler(LoginManager& loginManager, RequestHandlerFactory& handlerFactory)
    : m_loginManager(loginManager), m_handlerFactory(handlerFactory)
{
}

bool LoginRequestHandler::isRequestRelevant(RequestInfo request)
{
    return request.RequestId == int(CODES::LOGIN);
}

RequestResult LoginRequestHandler::handleRequest(RequestInfo request)
{
    if (isRequestRelevant(request)) //LOGIN
    {
         return login(request);
    }
    else if (request.RequestId == int(CODES::SIGN_UP))//SIGN UP
    {
        return signup(request);
    }
    else
    {
        std::vector<unsigned char> response;
        RequestResult result;
        ErrorResponse error = { "message" };
        response = JsonResponsePacketSerializer::serializeResponse(error);
        result.newHandler = nullptr;
        result.response = response;
        return result;
    }
}

RequestResult LoginRequestHandler::login(RequestInfo request)
{
    RequestResult result;
    //deserialize the request
    LoginRequest loginStruct = JsonRequestPacketDeserializer::deserializeLoginRequest(request.buffer);
    //build response
    LoginResponse login = { int(CODES::LOGIN) };
    std::vector<unsigned char> response = JsonResponsePacketSerializer::serializeResponse(login);
    
    result.response = response;
    result.newHandler = nullptr;
    return result;
}

RequestResult LoginRequestHandler::signup(RequestInfo request)
{
    RequestResult result;
    //deserialize the request
    SignupRequest signUpStruct = JsonRequestPacketDeserializer::deserializeSignupRequest(request.buffer);
    //build response
    SignupResponse signUp = { int(CODES::SIGN_UP) };
    std::vector<unsigned char> response = JsonResponsePacketSerializer::serializeResponse(signUp);
    
    result.response = response;
    result.newHandler = nullptr;
    return result;
}
