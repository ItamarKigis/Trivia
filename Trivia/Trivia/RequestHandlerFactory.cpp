#include "RequestHandlerFactory.h"

LoginRequestHandler* RequestHandlerFactory::createLoginRequestHandler()
{
    LoginManager& temp = m_loginManager;
    return new LoginRequestHandler(temp,*this);
}

LoginManager& RequestHandlerFactory::getLoginManager()
{
    return m_loginManager;
}