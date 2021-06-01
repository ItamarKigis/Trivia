#pragma once
#include <vector>
#include "Response.h"

enum class CODES {
	LOGIN = 200, SIGN_UP = 210, ERROR_CODE = 150, CREATE_ROOM_REQUEST = 101,
	GET_ROOMS_REQUEST = 102, GET_PLAYERS_IN_ROOM_REQUEST = 103, JOIN_ROOM_REQUEST = 104,
	GET_STATISTICS_REQUEST = 105, LOG_OUT_REQUEST = 106, HIGH_SCORE_REQUSET = 107,
	CLOSE_ROOM_REQUEST = 108, START_GAME_REQUEST = 109, GET_ROOM_STATE_REQUEST = 110, LEAVE_ROOM_REQUEST = 111};


class JsonResponsePacketSerializer
{
	static std::array<unsigned char, 4> intToBytes(int paramInt);
	static void addToPack(std::vector<unsigned char>& pack, const int size, const std::string jsonData);
public:
	static std::vector<unsigned char> serializeResponse(ErrorResponse response);
	static std::vector<unsigned char> serializeResponse(LoginResponse response);
	static std::vector<unsigned char> serializeResponse(SignupResponse response);
	static std::vector<unsigned char> serializeResponse(LogOutResponse response);
	static std::vector<unsigned char> serializeResponse(GetRoomsResponse response);
	static std::vector<unsigned char> serializeResponse(GetPlayersInRoomResponse response);
	static std::vector<unsigned char> serializeResponse(GetHighScoreResponse response);
	static std::vector<unsigned char> serializeResponse(GetPersonalStatsResponse response);
	static std::vector<unsigned char> serializeResponse(JoinRoomResponse response);
	static std::vector<unsigned char> serializeResponse(CreateRoomResponse response);
	
};