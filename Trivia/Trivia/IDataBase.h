#pragma once
#include <string>

class IDataBase
{
public:
	IDataBase();
	virtual ~IDataBase();
	virtual bool doesUserExists(const std::string) const = 0;
	virtual bool doesPasswordMatch(const std::string,const  std::string) const = 0;
	virtual void addNewUser(const std::string, const std::string,const std::string) const = 0;
};