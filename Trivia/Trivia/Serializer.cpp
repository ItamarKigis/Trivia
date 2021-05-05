#include "Serializer.h"
#include "json.hpp"
#include <bitset>

using json = nlohmann::json;
#define FOUR_BYTES 32
#define BYTE 8
#define BINARY 2
void JsonResponsePacketSerializer::pushValsToVector(std::vector<unsigned char>& pack, const std::string& sizeOfData,const std::string& data)
{
    for (int i = 0; i < sizeOfData.length(); i += BYTE)
    {
        unsigned char byte = stoi(sizeOfData.substr(i, i + BYTE), 0, BINARY);
        pack.push_back(byte);
    }
    for (int i = 0; i < data.length(); i += BYTE)
    {
        unsigned char byte = stoi(data.substr(i, i + BYTE), 0, BINARY);
        pack.push_back(byte);
    }
}

std::vector<unsigned char> JsonResponsePacketSerializer::serializeResponse(ErrorResponse response)
{
    std::vector<unsigned char> pack;
    json j;
    j["message"] = response.message;
    pack[0] = (int)CODES::ERROR;
    const std::string jsonMsg = std::bitset<FOUR_BYTES>(sizeof(j)).to_string();
    pushValsToVector(pack, jsonMsg, j.dump());
    return pack;
}

std::vector<unsigned char> JsonResponsePacketSerializer::serializeResponse(LoginResponse response)
{
    std::vector<unsigned char> pack;
    json j;
    j["status"] = response.status;
    pack[0] = (int)CODES::LOGIN;

    const std::string jsonMsg = std::bitset<FOUR_BYTES>(sizeof(j)).to_string();
    pushValsToVector(pack, jsonMsg, j.dump());
    return pack;
}

std::vector<unsigned char> JsonResponsePacketSerializer::serializeResponse(SignupResponse response)
{
    std::vector<unsigned char> pack;
    json j;
    j["status"] = response.status;
    pack[0] = (int)CODES::SIGN_UP;
    const std::string jsonMsg = std::bitset<FOUR_BYTES>(sizeof(j)).to_string();
    pushValsToVector(pack, jsonMsg, j.dump());
    return pack;
}
