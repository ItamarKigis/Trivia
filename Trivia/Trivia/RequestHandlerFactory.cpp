#include "RequestHandlerFactory.h"

RequestHandlerFactory::RequestHandlerFactory(LoginManager& manager, IDataBase& DB, statisticsManager& stats)
    : m_loginManager(manager), m_dataBase(&DB), m_StatisticsManager(stats)
{
    RoomManager m_roomManager;
}

MenuRequestHandler* RequestHandlerFactory::createMenuRequestHandler()
{
    RoomManager& temp = m_roomManager;
    statisticsManager& tempStats = m_StatisticsManager;
    return new MenuRequestHandler(LoggedUser(""), temp, tempStats, *this);
}

statisticsManager& RequestHandlerFactory::getStatisticsManager()
{
    return m_StatisticsManager;
}

RoomManager& RequestHandlerFactory::getRoomManager()
{
    return m_roomManager;
}

LoginRequestHandler* RequestHandlerFactory::createLoginRequestHandler()
{
    LoginManager& temp = m_loginManager;
    return new LoginRequestHandler(temp, *this);
}

LoginManager& RequestHandlerFactory::getLoginManager()
{
    return m_loginManager;
}