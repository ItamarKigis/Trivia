#include "Serializer.h"
#include "json.hpp"
#include <bitset>

using json = nlohmann::json;
#define FOUR_BYTES 32

void JsonResponsePacketSerializer::pushValsToVector(std::vector<unsigned char>& pack, const std::string& jsonMsg,const std::string& json)
{
    for (unsigned char let : jsonMsg)
    {
        pack.push_back(let);
    }
    for (unsigned char let : json)
    {
        pack.push_back(let);
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
