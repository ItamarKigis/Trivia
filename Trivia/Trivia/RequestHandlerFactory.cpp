#include "RequestHandlerFactory.h"

RequestHandlerFactory::RequestHandlerFactory(LoginManager& manager, IDataBase& DB) : m_loginManager(manager),
m_dataBase(&DB)
{
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