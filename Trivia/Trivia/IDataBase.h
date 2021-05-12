#pragma once
#include <string>

class IDataBase
{
public:
	IDataBase() {};
	virtual ~IDataBase() {};
	virtual bool doesUserExists(const std::string name) const = 0;
	virtual bool doesPasswordMatch(const std::string name, const  std::string pass) const = 0;
	virtual void addNewUser(const std::string name, const std::string pass, const std::string email) = 0;
};