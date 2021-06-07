#include "RoomAdminRequestHandler.h"

RoomAdminRequestHandler::RoomAdminRequestHandler(const Room room, const LoggedUser user, RoomManager& manager, RequestHandlerFactory& handlerFactory) :
	m_room(room), m_user(user), m_roomManager(manager), m_handlerFactory(handlerFactory)
{
}

RoomAdminRequestHandler::~RoomAdminRequestHandler()
{
}

bool RoomAdminRequestHandler::isRequestRelevant(RequestInfo request) const
{
	return request.RequestId == int(CODES::START_GAME_REQUEST) || request.RequestId == int(CODES::CLOSE_ROOM_REQUEST)
		|| request.RequestId == int(CODES::GET_ROOM_STATE_REQUEST);
}

RequestResult RoomAdminRequestHandler::handleRequest(RequestInfo request)
{
	if (!isRequestRelevant(request))
	{
		std::vector<unsigned char> response;
		RequestResult result;
		ErrorResponse error = { "ERROR" };
		response = JsonResponsePacketSerializer::serializeResponse(error);
		result.newHandler = nullptr;
		result.response = response;
		return result;
	}
	else
	{
		if (request.RequestId == int(CODES::START_GAME_REQUEST))
			return startGame(request);
		else if (request.RequestId == int(CODES::CLOSE_ROOM_REQUEST))
			return closeRoom(request);
		else
			return getRoomState(request);
	}
}

RequestResult RoomAdminRequestHandler::closeRoom(RequestInfo request) const
{
	RequestResult result;
	unsigned int code = 0;
	LeaveRoomResponse leaveRoom = { (unsigned char)CODES::LEAVE_ROOM_REQUEST };
	
	return RequestResult();
}

RequestResult RoomAdminRequestHandler::startGame(RequestInfo request) const
{
	RequestResult result;
	unsigned int code = 0;
	try 
	{
		result.newHandler = nullptr; //SOMETHING ELSE IDK WHAT
		code = (unsigned int)(CODES::START_GAME_REQUEST);
	}
	catch (const std::exception&)
	{
		result.newHandler = nullptr;
		code = (unsigned int)(CODES::ERROR_CODE);
	}

	StartGameResponse startGame = { code };
	std::vector<unsigned char> response = JsonResponsePacketSerializer::serializeResponse(startGame);
	result.response = response;
	return result;
}

RequestResult RoomAdminRequestHandler::getRoomState(RequestInfo request) const
{
	RequestResult result;
	unsigned int code = 0;

	try
	{

		m_roomManager.getRoomState();
		result.newHandler = nullptr;
		code = (unsigned int)(CODES::GET_ROOM_STATE_REQUEST);
	}
	catch (const std::exception&)
	{
		result.newHandler = nullptr;
		code = (unsigned int)(CODES::ERROR_CODE);
	}
	GetRoomStateResponse roomState = { code };
	std::vector<unsigned char> response = JsonResponsePacketSerializer::serializeResponse(roomState);
	result.response = response;
	return result;
}

