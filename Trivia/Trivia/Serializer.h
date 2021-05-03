#pragma once
#include <vector>

enum class CODES { LOGIN = 200, SIGN_UP = 210, ERROR = 500 };
class JsonResponsePacketSerializer
{
public:
	static std::vector<unsigned char> serializeResponse(ErrorResponse response);
	static std::vector<unsigned char> serializeResponse(LoginResponse response);
	static std::vector<unsigned char> serializeResponse(SignupResponse response);

};

