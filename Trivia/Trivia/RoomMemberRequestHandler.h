#pragma once
#include "IRequestHandler.h"
#include "Room.h"
#include "LoggedUser.h"
#include "RoomManager.h"
#include "RequestHandlerFactory.h"

class RoomMemberRequestHandler : public IRequestHandler
{
	Room m_room;
	LoggedUser m_user;
	RoomManager& m_roomManager;
	RequestHandlerFactory& m_handlerFactory;
	RequestResult leaveRoom(const RequestInfo request) const;
	RequestResult getRoomState(const RequestInfo request) const;
public:
	RoomMemberRequestHandler(const Room room, const LoggedUser user, RoomManager& manager, RequestHandlerFactory& handlerFactory);
	~RoomMemberRequestHandler();
	bool isRequestRelevant(const RequestInfo request) const override;
	RequestResult handleRequest(const RequestInfo request);
};

