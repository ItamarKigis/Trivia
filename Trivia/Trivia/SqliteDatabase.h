#pragma once
#include "IDataBase.h"

class SqliteDatabase : public IDataBase
{
	std::string _dbName;
	sqlite3* _db;
	void open();
	void close();
	static int getPasswordCallback(void* data, int argc, char** argv, char** azColName);
public:
	SqliteDatabase(const std::string dbName);
	~SqliteDatabase();
	virtual bool doesUserExists(std::string);
	virtual bool doesPasswordMatch(std::string, std::string);
	virtual void addNewUser(std::string, std::string, std::string);
	
};

