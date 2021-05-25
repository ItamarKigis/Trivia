#pragma once
#include "Question.h"
#include <string>
#include <list>
#include <vector>

class IDataBase
{
public:
	IDataBase() {};
	virtual ~IDataBase() {};
	virtual bool doesUserExists(const std::string name) const = 0;
	virtual bool doesPasswordMatch(const std::string name, const  std::string pass) const = 0;
	virtual void addNewUser(const std::string name, const std::string pass, const std::string email) = 0;
	virtual std::list<Question> getQuestions(const int num) const = 0;
	virtual float getPlayerAvgAnsTime(const std::string name) const = 0;
	virtual int getNumOfCorrectAnswers(const std::string username) const = 0;
	virtual int getNumOfTotalAnswers(const std::string username) const = 0;
	virtual int getNumOfPlayerGames(const std::string username) const = 0;
	virtual std::vector<std::string> getHighScore() const = 0;
};