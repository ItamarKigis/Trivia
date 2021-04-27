#pragma once
#include "json.hpp"
#include "Response.h"
#include <vector>

enum CODES { LOGIN = 200, SIGN_UP = 210, ERROR = 500 };
class JsonResponsePacketSerializer
{
public:
	static std::vector<unsigned char> serializeResponse(ErrorResponse res);
	static std::vector<unsigned char> serializeResponse(LoginResponse res);
	static std::vector<unsigned char> serializeResponse(SignupResponse res);

};

