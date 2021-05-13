#pragma once
#include <vector>
#include "Response.h"

enum class CODES { LOGIN = 200, SIGN_UP = 210, ERROR_CODE = 150 };
class JsonResponsePacketSerializer
{
	static std::array<unsigned char, 4> intToBytes(int paramInt);
	static void addToPack(std::vector<unsigned char>& pack, const int size, const std::string jsonData);
public:
	static std::vector<unsigned char> serializeResponse(ErrorResponse response);
	static std::vector<unsigned char> serializeResponse(LoginResponse response);
	static std::vector<unsigned char> serializeResponse(SignupResponse response);
	
};

