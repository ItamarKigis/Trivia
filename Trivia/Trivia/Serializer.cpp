#include "Serializer.h"
#include "json.hpp"
#include <bitset>

using json = nlohmann::json;
#define FOUR_BYTES 32
#define BYTE 8
#define BINARY 2
void JsonResponsePacketSerializer::pushValsToVector(std::vector<unsigned char>& pack, const std::string& sizeOfJsonMsg, const std::string& jsonMsg)
{
    for (int i = 0; i < sizeOfJsonMsg.length(); i += BYTE)
    {
        unsigned char byte = stoi(sizeOfJsonMsg.substr(i, i + BYTE), 0, BINARY);
        pack.push_back(byte);
    }
    for (int i = 0; i < jsonMsg.length(); i += BYTE)
    {
        unsigned char byte = stoi(jsonMsg.substr(i, i + BYTE), 0, BINARY);
        pack.push_back(byte);
    }
}

std::vector<unsigned char> JsonResponsePacketSerializer::serializeResponse(ErrorResponse response)
{
    std::vector<unsigned char> pack;
    json j;
    j["message"] = response.message;
    pack.push_back((int)CODES::ERROR_CODE);
    const std::string jsonMsgSize = std::bitset<FOUR_BYTES>(sizeof(j)).to_string();
    const std::string jsonMsg = std::bitset<sizeof(j)>(j.dump()).to_string();
    pushValsToVector(pack, jsonMsgSize, jsonMsg);
    return pack;
}

std::vector<unsigned char> JsonResponsePacketSerializer::serializeResponse(LoginResponse response)
{
    std::vector<unsigned char> pack;
    json j;
    j["status"] = response.status;
    pack.push_back((int)CODES::LOGIN);

    const std::string jsonMsgSize = std::bitset<FOUR_BYTES>(sizeof(j)).to_string();
    const std::string jsonMsg = std::bitset<sizeof(j)>(j.dump()).to_string();
    pushValsToVector(pack, jsonMsgSize, jsonMsg);
    return pack;
}

std::vector<unsigned char> JsonResponsePacketSerializer::serializeResponse(SignupResponse response)
{
    std::vector<unsigned char> pack;
    json j;
    j["status"] = response.status;
    pack.push_back((int)CODES::SIGN_UP);
    const std::string jsonMsgSize = std::bitset<FOUR_BYTES>(sizeof(j)).to_string();
    const std::string jsonMsg = std::bitset<sizeof(j)>(j.dump()).to_string();
    pushValsToVector(pack, jsonMsgSize, jsonMsg);
    return pack;
}
