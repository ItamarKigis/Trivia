#pragma once
#include <vector>
#include "Response.h"
enum class CODES { LOGIN = 200, SIGN_UP = 210, ERROR_CODE = 500 };
class JsonResponsePacketSerializer
{
	static void pushValsToVector(std::vector<unsigned char>& pack, const std::string& size, const std::string& json);
public:
	static std::vector<unsigned char> serializeResponse(ErrorResponse response);
	static std::vector<unsigned char> serializeResponse(LoginResponse response);
	static std::vector<unsigned char> serializeResponse(SignupResponse response);

};

