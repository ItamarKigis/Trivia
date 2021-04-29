#include "Serializer.h"
#include <bitset>
using json = nlohmann::json;

std::vector<unsigned char> JsonResponsePacketSerializer::serializeResponse(ErrorResponse res)
{
    std::vector<unsigned char> pack;
    json j;
    j["message"] = res.message;
    pack[0] = ERROR;
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

std::vector<unsigned char> JsonResponsePacketSerializer::serializeResponse(LoginResponse res)
{
    return std::vector<unsigned char>();
}

std::vector<unsigned char> JsonResponsePacketSerializer::serializeResponse(SignupResponse res)
{
    return std::vector<unsigned char>();
}
