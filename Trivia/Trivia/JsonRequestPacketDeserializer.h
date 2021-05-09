#pragma once
#include <vector>
#include <string>
#include "json.hpp"
#define START_DATA 5
#define INDEX_OF_CODE 0
using json = nlohmann::json;

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
	static int GetDataLenght(std::vector<unsigned char>Buffer);
	static json GetJson(std::vector<unsigned char>Buffer, int dataLengh);
};