#pragma once
#include "IDataBase.h"
#include "sqlite3 .h"

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
	virtual std::list<Question> getQuestions(const int num) const override;
	virtual float getPlayerAvgAnsTime(const std::string name) const override;
	virtual int getNumOfCorrectAnswers(const std::string username) const override;
	virtual int getNumOfTotalAnswers(const std::string username) const override;
	virtual int getNumOfPlayerGames(const std::string username) const override;
	virtual std::vector<std::string> getHighScore() const override;
};

