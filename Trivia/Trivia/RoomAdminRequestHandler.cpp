#include "RoomAdminRequestHandler.h"

RoomAdminRequestHandler::RoomAdminRequestHandler(const Room room, const LoggedUser user, RoomManager& manager, RequestHandlerFactory& handlerFactory) :
	m_room(room), m_user(user), m_roomManager(manager), m_handlerFactory(handlerFactory)
{}

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

