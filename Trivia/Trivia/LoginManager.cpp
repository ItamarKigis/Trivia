#include "LoginManager.h"
#include <iostream>

LoginManager::LoginManager(IDataBase* DB)
{
	if (DB == nullptr)
		std::cerr << "couldnt open DB" << std::endl;
	m_database = DB;
}

LoginManager::~LoginManager()
{
	m_loggedUsers.clear();
}

void LoginManager::signUp(const std::string name, const std::string pass, const std::string email)
{
	bool userExists = m_database->doesUserExists(name);
	if (!userExists)
		m_database->addNewUser(name, pass, email);
}

void LoginManager::login(const std::string name, const std::string pass)
{
	bool userExists = m_database->doesUserExists(name);
	bool correctPass = m_database->doesPasswordMatch(name, pass);
	if (correctPass && userExists)
		m_loggedUsers.push_back(LoggedUser(name));
}

void LoginManager::logOut(const std::string name)
{
	for (auto it = m_loggedUsers.begin(); it != m_loggedUsers.end(); it++)
	{
		if (it->getUsername() == name)
		{
			m_loggedUsers.erase(it);
			break;
		}
	}
}
