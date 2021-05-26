#pragma once
#include "IRequestHandler.h"
#include "RoomManager.h"
#include "RequestHandlerFactory.h"
#include "statisticsManager.h"
class RequestHandlerFactory;
class LoginManager;
class MenuRequestHandler : public IRequestHandler
{
public:
	MenuRequestHandler(LoggedUser user, RoomManager& manager, statisticsManager& stats, RequestHandlerFactory& factoryHandler);
	~MenuRequestHandler() override = default;
	bool isRequestRelevant(RequestInfo request) const override;
	RequestResult handleRequest(RequestInfo request) override;
private:
	LoggedUser m_user;
	RoomManager& m_roomManager;
	statisticsManager& m_statisticsManager;
	RequestHandlerFactory& m_handlerFactory;

	RequestResult signout(RequestInfo request);
	RequestResult getRooms(RequestInfo request);
	RequestResult getPlayersInRoom(RequestInfo request);
	RequestResult getPersonalStats(RequestInfo request);
	RequestResult getHighScore(RequestInfo request);
	RequestResult joinRoom(RequestInfo request);
	RequestResult createRoom(RequestInfo request);
};