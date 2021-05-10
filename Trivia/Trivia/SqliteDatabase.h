#pragma once
#include "IDataBase.h"
class SqliteDatabase : public IDataBase
{
	virtual bool doesUserExists(std::string);
	virtual bool doesPasswordMatch(std::string, std::string);
	virtual void addNewUser(std::string, std::string, std::string);
};

