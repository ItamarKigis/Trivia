#pragma once
#include "LoginRequestHandler.h"
#include "LoginManager.h"
#include "RoomManager.h"
#include "statisticsManager.h"
#include "RoomAdminRequestHandler.h"
#include "RoomMemberRequestHandler.h"

class LoginRequestHandler;
class LoginManager;
class MenuRequestHandler;
class RoomAdminRequestHandler;
class RoomMemberRequestHandler;

class RequestHandlerFactory
{
public:
	LoginRequestHandler* createLoginRequestHandler();
	LoginManager& getLoginManager();
	RequestHandlerFactory(LoginManager& manager, IDataBase& DB, statisticsManager& stats);

	MenuRequestHandler* createMenuRequestHandler();
	statisticsManager& getStatisticsManager();
	RoomManager& getRoomManager();

	RoomAdminRequestHandler* createRoomAdminRequestHandler();
	RoomMemberRequestHandler* createRoomAdminMemberRequestHandler();

private:
	LoginManager m_loginManager;
	IDataBase* m_dataBase;

	RoomManager m_roomManager;
	statisticsManager m_StatisticsManager;
};
