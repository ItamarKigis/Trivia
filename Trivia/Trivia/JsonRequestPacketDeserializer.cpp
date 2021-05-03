#include "JsonRequestPacketDeserializer.h"

LoginRequest JsonRequestPacketDeserializer::deserializeLoginRequest(std::vector<unsigned char> Buffer)
{
    //getting the code
    int code = int(Buffer[INDEX_OF_CODE]);
    //getting the message lengh
    int dataLengh = GetDataLenght(Buffer);
    //put the data into json format
    json j = GetJson(Buffer);
    //creating new struct with the json data
    LoginRequest newLogin;
    newLogin.username = j["username"];
    newLogin.password = j["password"];
    return newLogin;
}

SignupRequest JsonRequestPacketDeserializer::deserializeSignupRequest(std::vector<unsigned char> Buffer)
{
    //getting the code
    int code = int(Buffer[INDEX_OF_CODE]);
    //getting the message lengh
    int dataLengh = GetDataLenght(Buffer);

    //put the data into json format
    json j = GetJson(Buffer);
    //creating new struct with the json data
    SignupRequest signUp;
    signUp.username = j["username"];
    signUp.password = j["password"];
    signUp.email = j["email"];
    return signUp;
}

int JsonRequestPacketDeserializer::GetDataLenght(std::vector<unsigned char> Buffer)
{
    return int((unsigned char)(Buffer[1]) << 24 |
        (unsigned char)(Buffer[2]) << 16 |
        (unsigned char)(Buffer[3]) << 8 |
        (unsigned char)(Buffer[4]));
}

json JsonRequestPacketDeserializer::GetJson(std::vector<unsigned char> Buffer)
{
    std::vector<unsigned char> Bdata;
    std::vector<unsigned char>::iterator ptr = Buffer.begin() + START_DATA;
    while (ptr != Buffer.end())
    {
        Bdata.push_back(*ptr);
        ++ptr;
    }
    return json::from_bson(Bdata);
}
