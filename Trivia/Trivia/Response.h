#pragma once
#include <string>
#include "RoomData.h"
#include <map>
typedef struct LoginResponse {
	unsigned int status;
} LoginResponse;

typedef struct SignupResponse {
	unsigned int status;
} SignupResponse;

typedef struct LogOutResponse {
	unsigned int status;
} LogOutResponse;

typedef struct ErrorResponse {
	std::string message;
} ErrorResponse;

typedef struct GetRoomsResponse {
	unsigned int status;
	std::vector<RoomData> rooms;
} GetRoomsResponse;

typedef struct GetPlayersInRoomResponse {
	std::vector<std::string> players;
} GetPlayersInRoomResponse;

typedef struct GetHighScoreResponse {
	unsigned int status;
	std::vector<std::string> stats;
} GetHighScoreResponse;

typedef struct GetPersonalStatsResponse {
	unsigned int status;
	std::vector<std::string> stats;
} GetPersonalStatsResponse;

typedef struct JoinRoomResponse {
	unsigned int status;
} JoinRoomResponse;

typedef struct CreateRoomResponse {
	unsigned int status;
} CreateRoomResponse;

typedef struct CloseRoomResponse {
	unsigned int status;
} CloseRoomResponse;

typedef struct StartGameResponse {
	unsigned int status;
} StartGameResponse;

typedef struct LeaveRoomResponse {
	unsigned int status;
} LeaveRoomResponse;

typedef struct GetRoomStateResponse {
	unsigned int status;
	bool hasGameBegun;
	std::vector<std::string> players;
	unsigned int questionCount;
	unsigned int answerTimeOut;
} GetRoomStateResponse;

typedef struct LeaveGameResponse {
	unsigned int status;
} LeaveGameResponse;

typedef struct SumbitAnswerResponse {
	unsigned int status;
	unsigned int correctAnswers;
} SumbitAnswerResponse;

typedef struct GetQuestionsResponse {
	unsigned int status;
	std::string question;
	std::map<unsigned int, std::string> answers;
} GetQuestionsResponse;

typedef struct PlayerResults {
	std::string username;
	unsigned int correctAnswersCount;
	unsigned int wrongAnswersCount;
	float averageAnswersTime;
} PlayerResults;

typedef struct GetGameResultsResponse {
	unsigned int status;
	std::vector<PlayerResults> results;
} GetGameResultsResponse;