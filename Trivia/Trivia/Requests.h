#pragma once
typedef struct LoginRequest
{
public:
	std::string username;
	std::string password;
}LoginRequest;

typedef struct SignupRequest
{
public:
	std::string username;
	std::string password;
	std::string email;
}SignupRequest;

typedef struct GetPlayersInRoomRequest
{
public:
	unsigned int roomId;
}GetPlayersInRoomRequest;

typedef struct JoinRoomRequest
{
public:
	unsigned int roomId;
}JoinRoomRequest;

typedef struct CreateRoomRequest
{
public:
	std::string roomName;
	unsigned int maxUsers;
	unsigned int questionCount;
	unsigned int answerTimeout;
}CreateRoomRequest;