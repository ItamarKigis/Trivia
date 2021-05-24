#include "statisticsManager.h"
#include <iostream>
statisticsManager::statisticsManager(IDataBase* DB)
{
	if (DB == nullptr)
		std::cerr << "couldnt open DB" << std::endl;
	m_database = DB;
}

statisticsManager::~statisticsManager()
{
}

std::vector<std::string> statisticsManager::getStatistics() const
{

	return std::vector<std::string>();
}

std::vector<std::string> statisticsManager::getHighScore() const
{
	return std::vector<std::string>();
}

std::vector<std::string> statisticsManager::getUserStatistics(const std::string name) const
{
	return std::vector<std::string>();
}
