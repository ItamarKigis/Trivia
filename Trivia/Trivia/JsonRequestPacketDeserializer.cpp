#include "JsonRequestPacketDeserializer.h"
#include "json.hpp"
using json = nlohmann::json;
LoginRequest JsonRequestPacketDeserializer::deserializeLoginRequest(std::vector<unsigned char> Buffer)
{
    //getting the code
    int code = int(Buffer[0]);
    //getting the message lengh
    int dataLengh = int((unsigned char)(Buffer[1]) << 24 |
        (unsigned char)(Buffer[2]) << 16 |
        (unsigned char)(Buffer[3]) << 8 |
        (unsigned char)(Buffer[4]));
    
    //put the data into json format
    std::vector<unsigned char> Bdata;
    std::vector<unsigned char>::iterator ptr = Buffer.begin() + 5;
    while (ptr != Buffer.end())
    {
        Bdata.push_back(*ptr);
        ++ptr;
    }
    json j = json::from_bson(Bdata);
    //creating new struct with the json data
    LoginRequest newLogin;
    newLogin.username = j["username"];
    newLogin.password = j["password"];
    return newLogin;
}
