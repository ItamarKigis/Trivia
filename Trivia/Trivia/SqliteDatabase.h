#pragma once
#include "IDataBase.h"
#include "sqlite3.h"

class SqliteDatabase : public IDataBase
{
	std::string _dbName;
	sqlite3* _db;
	void open();
	void close();
	static int getPasswordCallback(void* data, int argc, char** argv, char** azColName);
	static int userExistsCallback(void* data, int argc, char** argv, char** azColName);
public:
	SqliteDatabase(const std::string dbName);
	~SqliteDatabase() override;
	virtual bool doesUserExists(const std::string name) const override;
	virtual bool doesPasswordMatch(const std::string name, const std::string pass) const override;
	virtual void addNewUser(const std::string name, const std::string pass, const std::string email) override;
	
};
