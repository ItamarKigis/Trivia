#pragma once
#include "IDataBase.h"
#include <string>
#include <vector>

class statisticsManager
{
	IDataBase* m_database;
public:
	statisticsManager();
	~statisticsManager();
	std::vector<std::string> getStatistics() const;
	std::vector<std::string> getHighScore() const;
	std::vector<std::string> getUserStatistics(const std::string name) const;
};

