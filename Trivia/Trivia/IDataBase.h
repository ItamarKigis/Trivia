#pragma once
#include <string>

class IDataBase
{
public:
	virtual bool doesUserExists(std::string) = 0;
	virtual bool doesPasswordMatch(std::string, std::string) = 0;
	virtual void addNewUser(std::string, std::string, std::string) = 0;
};