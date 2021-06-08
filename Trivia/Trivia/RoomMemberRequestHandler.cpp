#include "RoomMemberRequestHandler.h"

RoomMemberRequestHandler::RoomMemberRequestHandler(const Room room, const LoggedUser user, RoomManager& manager, RequestHandlerFactory& handlerFactory) :
	m_room(room), m_user(user), m_roomManager(manager), m_handlerFactory(handlerFactory)
{
}

RoomMemberRequestHandler::~RoomMemberRequestHandler()
{
}

bool RoomMemberRequestHandler::isRequestRelevant(RequestInfo request) const
{
	return request.RequestId == (int)CODES::LEAVE_ROOM_REQUEST || request.RequestId == (int)CODES::GET_ROOM_STATE_REQUEST;
}

RequestResult RoomMemberRequestHandler::handleRequest(RequestInfo request)
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
		if (request.RequestId == int(CODES::GET_ROOM_STATE_REQUEST))
			return getRoomState(request);
		else if (request.RequestId == int(CODES::LEAVE_ROOM_REQUEST))
			return leaveRoom(request);
	}
}

RequestResult RoomMemberRequestHandler::leaveRoom(RequestInfo request) const
{
	RequestResult result;
	unsigned int code = 0;
	try
	{
		result.newHandler = new MenuRequestHandler(m_user, m_handlerFactory.getRoomManager(),
			m_handlerFactory.getStatisticsManager(), m_handlerFactory);
		code = (unsigned char)CODES::LEAVE_ROOM_REQUEST;
	}
	catch (const std::exception&)
	{
		result.newHandler = nullptr;
		code = (unsigned int)(CODES::ERROR_CODE);
	}
	StartGameResponse leaveRoom = { code };
	std::vector<unsigned char> response = JsonResponsePacketSerializer::serializeResponse(leaveRoom);
	result.response = response;
	return result;
}

RequestResult RoomMemberRequestHandler::getRoomState(RequestInfo request) const
{
	RequestResult result;
	unsigned int code = 0;

	try
	{
		code = m_roomManager.getRoomState(m_room.getRoomData().id);
		//at this point i use it as a bool, might change it later
		if (code == 0) //IDK WHAT IS THE CODE SUPPOSED TO BE - ITS ACCORDING TO isActive FIELD IN roomData
			result.newHandler = new RoomAdminRequestHandler(m_room, m_user, m_roomManager, m_handlerFactory);
		else
			result.newHandler = nullptr;// IN V4.0.0 AFTER WE BUILD startGameHandler the newHandler will be it.
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