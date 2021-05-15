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
    int code = 0;
    //deserialize the request
    LoginRequest loginStruct = JsonRequestPacketDeserializer::deserializeLoginRequest(request.buffer);
    try
    {
        m_loginManager.login(loginStruct.username, loginStruct.password);
        code = int(CODES::LOGIN);
        result.newHandler = new MenuRequestHandler();
    }
    catch(...)
    {
        code = int(CODES::ERROR_CODE);
        result.newHandler = nullptr;
    }
    //build response
    LoginResponse login = { code };
    std::vector<unsigned char> response = JsonResponsePacketSerializer::serializeResponse(login);    
    result.response = response;
    return result;
}

RequestResult LoginRequestHandler::signup(RequestInfo request)
{
    RequestResult result;
    int code = 0;
    //deserialize the request
    SignupRequest signUpStruct = JsonRequestPacketDeserializer::deserializeSignupRequest(request.buffer);
    try
    {
        m_loginManager.signUp(signUpStruct.username, signUpStruct.password, signUpStruct.email);
        result.newHandler = new MenuRequestHandler();
        code = int(CODES::SIGN_UP);
    }
    catch (...)
    {
        result.newHandler = nullptr;
        code = int(CODES::ERROR_CODE);
    }
    //build response
    SignupResponse signUp = { code };
    std::vector<unsigned char> response = JsonResponsePacketSerializer::serializeResponse(signUp);
    result.response = response;
    return result;
}
