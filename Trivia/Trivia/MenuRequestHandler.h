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
	bool isRequestRelevant(const RequestInfo request) const override;
	RequestResult handleRequest(const RequestInfo request) override;
private:
	LoggedUser m_user;
	RoomManager& m_roomManager;
	statisticsManager& m_statisticsManager;
	RequestHandlerFactory& m_handlerFactory;

	RequestResult signout(const RequestInfo request);
	RequestResult getRooms(const RequestInfo request);
	RequestResult getPlayersInRoom(const RequestInfo request);
	RequestResult getPersonalStats(const RequestInfo request);
	RequestResult getHighScore(const RequestInfo request);
	RequestResult joinRoom(const RequestInfo request);
	RequestResult createRoom(const RequestInfo request);
};