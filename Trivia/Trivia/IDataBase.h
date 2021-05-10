#pragma once
#include <string>

class IDataBase
{
public:
	virtual bool doesUserExists(std::string);
	virtual bool doesPasswordMatch(std::string, std::string);
	virtual void addNewUser(std::string, std::string, std::string);
};