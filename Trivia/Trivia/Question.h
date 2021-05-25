#pragma once
#include <string>
#include <array>

typedef struct Question {
	std::string question;
	std::string correctAns;
	std::array<std::string, 3> wrongAnwers;
} Question;