#include "LoggedUser.h"

LoggedUser::LoggedUser(const std::string name) : m_username(name)
{
}

LoggedUser::~LoggedUser()
{
}

std::string LoggedUser::getUsername() const
{
	return m_username;
}