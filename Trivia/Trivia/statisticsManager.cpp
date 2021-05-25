#include "statisticsManager.h"
#include <iostream>
#include <string>
statisticsManager::statisticsManager(IDataBase* DB)
{
	if (DB == nullptr)
		std::cerr << "couldnt open DB" << std::endl;
	m_database = DB;
}

statisticsManager::~statisticsManager()
{
}

std::vector<std::string> statisticsManager::getHighScore() const
{
	return std::vector<std::string>();
}

std::vector<std::string> statisticsManager::getUserStatistics(const std::string name) const
{
	std::string correctAnswers = std::to_string(m_database->getNumOfCorrectAnswers(name));
	std::string games = std::to_string(m_database->getNumOfPlayerGames(name));
	std::string totalAnswers = std::to_string(m_database->getNumOfTotalAnswers(name));
	std::string avgAnsTime = std::to_string(m_database->getPlayerAvgAnsTime(name));
	std::vector<std::string> stats = { correctAnswers, games, totalAnswers, avgAnsTime };
	return stats;
}
