#pragma once
#include <vector>
#include "Response.h"
#include "json.hpp"

enum class CODES { LOGIN = 200, SIGN_UP = 210, ERROR_CODE = 150 };
class JsonResponsePacketSerializer
{
	static std::array<unsigned char, 4> intToBytes(int paramInt);
	static void valsToVector(std::vector<unsigned char>& vec, json& j);
public:
	static std::vector<unsigned char> serializeResponse(ErrorResponse response);
	static std::vector<unsigned char> serializeResponse(LoginResponse response);
	static std::vector<unsigned char> serializeResponse(SignupResponse response);
	
};

