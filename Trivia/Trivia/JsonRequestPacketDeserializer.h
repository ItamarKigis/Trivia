#pragma once
#include <vector>
#include <string>
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

class JsonRequestPacketDeserializer
{
public:
	static LoginRequest deserializeLoginRequest(std::vector<unsigned char> Buffer);
	static SignupRequest deserializeSignupRequest(std::vector<unsigned char> Buffer);
private:
	//int GetDataLenght(std::vector<unsigned char>Buffer);
};