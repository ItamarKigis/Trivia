#include "MenuRequestHandler.h"

MenuRequestHandler::MenuRequestHandler(LoggedUser user, RoomManager& manager, 
    statisticsManager& stats, RequestHandlerFactory& factoryHandler) : m_roomManager(manager),
    m_statisticsManager(stats), m_handlerFactory(m_handlerFactory), m_user(user)
{
}
bool MenuRequestHandler::isRequestRelevant(const RequestInfo request) const
{
    return request.RequestId == int(CODES::CREATE_ROOM_REQUEST) ||
        request.RequestId == int(CODES::GET_ROOMS_REQUEST) ||
        request.RequestId == int(CODES::GET_PLAYERS_IN_ROOM_REQUEST) ||
        request.RequestId == int(CODES::JOIN_ROOM_REQUEST) ||
        request.RequestId == int(CODES::GET_STATISTICS_REQUEST) ||
        request.RequestId == int(CODES::HIGH_SCORE_REQUSET) ||
        request.RequestId == int(CODES::LOG_OUT_REQUEST);
}

RequestResult MenuRequestHandler::handleRequest(const RequestInfo request)
{
    if (!(this->isRequestRelevant(request)))
    {
        std::vector<unsigned char> response;
        RequestResult result;
        ErrorResponse error = { "error" };
        response = JsonResponsePacketSerializer::serializeResponse(error);
        result.newHandler = nullptr;
        result.response = response;
        return result;
    }

    if (request.RequestId == int(CODES::CREATE_ROOM_REQUEST))
    {
        return createRoom(request);
    }
    else if(request.RequestId == int(CODES::GET_ROOMS_REQUEST))
    {
        return getRooms(request);
    }
    else if (request.RequestId == int(CODES::GET_PLAYERS_IN_ROOM_REQUEST))
    {
        return getPlayersInRoom(request);
    }
    else if (request.RequestId == int(CODES::JOIN_ROOM_REQUEST))
    {
        return joinRoom(request);
    }
    else if(request.RequestId == int(CODES::GET_STATISTICS_REQUEST))
    {
        return getPersonalStats(request);
    }
    else if(request.RequestId == int(CODES::LOG_OUT_REQUEST))
    {
        return signout(request);
    }
    else//HIGH SCORE request
    {
        return getHighScore(request);
    }
}

RequestResult MenuRequestHandler::getRooms(const RequestInfo request)
{
    RequestResult result;
    GetRoomsResponse response;
    int code = 0;
    try
    {
        response.rooms = m_roomManager.getRooms();
        code = int(CODES::GET_ROOMS_REQUEST);
        result.newHandler = this;
    }
    catch (std::exception& e)
    {
        code = int(CODES::ERROR_CODE);
    }
    response.status = code;

    result.response = JsonResponsePacketSerializer::serializeResponse(response);
    //newHandler is MenuRequestHandler. So there is no need to set this field
    return result;
}

RequestResult MenuRequestHandler::getPlayersInRoom(const RequestInfo request)
{
    RequestResult result;
    GetPlayersInRoomResponse response;
    GetPlayersInRoomRequest RequestStruct = JsonRequestPacketDeserializer::deserializeGetPlayersRequest(request.buffer);
    int code = 0;

    try
    {
        response.players = m_roomManager.getRoom(RequestStruct.roomId).getAllUsers();
    }
    catch (std::exception& e)
    {

    }
    result.response = JsonResponsePacketSerializer::serializeResponse(response);
    //newHandler is MenuRequestHandler. So there is no need to set this field
    return result;
}

RequestResult MenuRequestHandler::getPersonalStats(const RequestInfo request)
{
    RequestResult result;
    GetPersonalStatsResponse response;
    int code = 0;
    try
    {
        response.stats = m_statisticsManager.getUserStatistics(m_user.getUsername());
        code = int(CODES::GET_STATISTICS_REQUEST);
        result.newHandler = this;
    }
    catch (std::exception& e)
    {
        code = int(CODES::ERROR_CODE);
    }
    response.status = code;
    result.response = JsonResponsePacketSerializer::serializeResponse(response);
    return result;
}

RequestResult MenuRequestHandler::getHighScore(const RequestInfo request)
{
    RequestResult result;
    GetHighScoreResponse response;
    int code = 0;
    try
    {
        response.stats = m_statisticsManager.getHighScore();
        code = int(CODES::HIGH_SCORE_REQUSET);
        result.newHandler = this;
    }
    catch(std::exception& e)
    {
        code = int(CODES::ERROR_CODE);
    }
    response.status = code;

    result.response = JsonResponsePacketSerializer::serializeResponse(response);
    return result;
}

RequestResult MenuRequestHandler::joinRoom(const RequestInfo request)
{
    RequestResult result;
    JoinRoomRequest requestStruct = JsonRequestPacketDeserializer::deserializeJoinRoomRequest(request.buffer);
    JoinRoomResponse response;
    try
    {
        m_roomManager.getRoom(requestStruct.roomId).addUser(m_user);
        response.status = int(CODES::JOIN_ROOM_REQUEST);
    }
    catch (std::exception& e)
    {
        response.status = int(CODES::ERROR_CODE);
    }
    result.response = JsonResponsePacketSerializer::serializeResponse(response);
    //newHandler is MenuRequestHandler. So there is no need to set this field
    return result;
}

RequestResult MenuRequestHandler::createRoom(const RequestInfo request)
{
    RequestResult result;
    CreateRoomRequest requestStruct = JsonRequestPacketDeserializer::deserializeCreateRoomRequest(request.buffer);
    CreateRoomResponse response;
    try
    {
        RoomData data = { m_roomManager.CurrentRoomId, requestStruct.roomName, requestStruct.maxUsers,
            requestStruct.questionCount, requestStruct.answerTimeout, true };
        m_roomManager.createRoom(m_user , data);
        response.status = int(CODES::CREATE_ROOM_REQUEST);
        result.newHandler = this;
    }
    catch(std::exception& e)
    {
        response.status = int(CODES::ERROR_CODE);
    }
    result.response = JsonResponsePacketSerializer::serializeResponse(response);
    
    return result;
}


RequestResult MenuRequestHandler::signout(const RequestInfo request)
{
    RequestResult result;
    LogOutResponse response;
    try
    {
        m_roomManager.deleteUser(m_user);
        response.status = int(CODES::LOG_OUT_REQUEST);
    }
    catch (std::exception& e)
    {
        response.status = int(CODES::ERROR_CODE);
    }
    result.response = JsonResponsePacketSerializer::serializeResponse(response);
    result.newHandler = nullptr; //here the newHandler is nullptr because the user is logging out
    return result;
}