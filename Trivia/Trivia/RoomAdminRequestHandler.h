#pragma once
#include "IRequestHandler.h"
#include "Room.h"
#include "LoggedUser.h"
#include "RoomManager.h"
#include "RequestHandlerFactory.h"

class RequestHandlerFactory;
class LoginManager;

class RoomAdminRequestHandler : public IRequestHandler
{
	Room m_room;
	LoggedUser m_user;
	RoomManager& m_roomManager;
	RequestHandlerFactory& m_handlerFactory;
public:
	RoomAdminRequestHandler(const Room room, const LoggedUser user, RoomManager& manager, RequestHandlerFactory& handlerFactory);
	~RoomAdminRequestHandler();
	bool isRequestRelevant(RequestInfo request) const override;
	RequestResult handleRequest(RequestInfo request);
	RequestResult closeRoom(RequestInfo request) const;
	RequestResult startGame(RequestInfo request) const;
	RequestResult getRoomState(RequestInfo request) const;
};

