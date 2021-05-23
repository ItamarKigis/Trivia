#pragma once
#include <string>

class LoggedUser 
{
	std::string m_username;
public:
	LoggedUser(const std::string name);
	~LoggedUser();
	std::string getUsername() const;
	bool operator==(const LoggedUser other);
};