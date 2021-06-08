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

	return RequestResult();
}

RequestResult RoomMemberRequestHandler::getRoomState(RequestInfo request) const
{
	return RequestResult();
}