#pragma once
#include <vector>
#include <string>
#include "json.hpp"
#include "Requests.h"
#define START_DATA 5
#define INDEX_OF_CODE 0
using json = nlohmann::json;


class JsonRequestPacketDeserializer
{
public:
	static LoginRequest deserializeLoginRequest(std::vector<unsigned char> Buffer);
	static SignupRequest deserializeSignupRequest(std::vector<unsigned char> Buffer);
	static GetPlayersInRoomRequest deserializeGetPlayersRequest(std::vector<unsigned char> Buffer);
	static JoinRoomRequest deserializeJoinRoomRequest(std::vector<unsigned char> Buffer);
	static CreateRoomRequest deserializeCreateRoomRequest(std::vector<unsigned char> Buffer);
	static SumbitAnsweRequest deserializeSumbitAnswerRequest(std::vector<unsigned char> Buffer);
private:
	static int GetDataLenght(std::vector<unsigned char>Buffer);
	static json GetJson(std::vector<unsigned char>Buffer, int dataLengh);
};