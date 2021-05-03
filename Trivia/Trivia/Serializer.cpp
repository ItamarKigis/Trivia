#include "Serializer.h"
#include "json.hpp"
#include "Response.h"
#include <bitset>
using json = nlohmann::json;

std::vector<unsigned char> JsonResponsePacketSerializer::serializeResponse(ErrorResponse response)
{
    std::vector<unsigned char> pack;
    json j;
    j["message"] = response.message;
    pack[0] = (int)CODES::ERROR;
    std::string size = std::bitset<32>(sizeof(j)).to_string();
    for (unsigned char let : size)
    {
        pack.push_back(let);
    }
    std::string msg = j.dump();
    for (unsigned char let : msg)
    {
        pack.push_back(let);
    }
    return pack;
}

std::vector<unsigned char> JsonResponsePacketSerializer::serializeResponse(LoginResponse response)
{
    std::vector<unsigned char> pack;
    json j;
    j["status"] = response.status;
    pack[0] = (int)CODES::LOGIN;
    std::string size = std::bitset<32>(sizeof(j)).to_string();
    for (unsigned char let : size)
    {
        pack.push_back(let);
    }
    std::string msg = j.dump();
    for (unsigned char let : msg)
    {
        pack.push_back(let);
    }
    return pack;
}

std::vector<unsigned char> JsonResponsePacketSerializer::serializeResponse(SignupResponse response)
{
    std::vector<unsigned char> pack;
    json j;
    j["status"] = response.status;
    pack[0] = (int)CODES::SIGN_UP;
    std::string size = std::bitset<32>(sizeof(j)).to_string();
    for (unsigned char let : size)
    {
        pack.push_back(let);
    }
    std::string msg = j.dump();
    for (unsigned char let : msg)
    {
        pack.push_back(let);
    }
    return pack;
}
