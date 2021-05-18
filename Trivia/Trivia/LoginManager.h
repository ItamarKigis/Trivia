#pragma once
#include "LoggedUser.h"
#include "IDataBase.h"
#include <vector>

class LoginManager
{
	IDataBase* m_database;
	std::vector<LoggedUser> m_loggedUsers;
public:
	LoginManager(IDataBase* DB);
	~LoginManager();
	void signUp(const std::string name, const std::string pass, const std::string email);
	void login(const std::string name, const std::string pass);
	void logOut(const std::string name);
	bool IsUserConnected(const std::string name);
};

