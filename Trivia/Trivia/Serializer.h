#pragma once
#include <vector>
#include "Response.h"

enum class CODES { LOGIN = 200, SIGN_UP = 210, ERROR_CODE = 150, CREATE_ROOM_REQUEST = 101,
	GET_ROOMS_REQUEST = 102, GET_PLAYERS_IN_ROOM_REQUEST = 103, JOIN_ROOM_REQUEST = 104,
	GET_STATISTICS_REQUEST = 105, LOG_OUT_REQUEST = 106};
class JsonResponsePacketSerializer
{
	static std::array<unsigned char, 4> intToBytes(int paramInt);
	static void addToPack(std::vector<unsigned char>& pack, const int size, const std::string jsonData);
public:
	static std::vector<unsigned char> serializeResponse(ErrorResponse response);
	static std::vector<unsigned char> serializeResponse(LoginResponse response);
	static std::vector<unsigned char> serializeResponse(SignupResponse response);
	
};