#include "JsonRequestPacketDeserializer.h"

LoginRequest JsonRequestPacketDeserializer::deserializeLoginRequest(std::vector<unsigned char> Buffer)
{
    //getting the code
    int code = int(Buffer[0]);
    //getting the message lengh
    int dataLengh = GetDataLenght(Buffer);
    //put the data into json format
    json json_data = GetJson(Buffer, dataLengh);
    //creating new struct with the json data
    LoginRequest newLogin;
    newLogin.username = json_data["username"];
    newLogin.password = json_data["password"];
    return newLogin;
}

SignupRequest JsonRequestPacketDeserializer::deserializeSignupRequest(std::vector<unsigned char> Buffer)
{
    //getting the code
    int code = int(Buffer[0]);
    //getting the message lengh
    int dataLengh = GetDataLenght(Buffer);

    //put the data into json format
    json json_data = GetJson(Buffer, dataLengh);
    //creating new struct with the json data
    SignupRequest signUp;
    signUp.username = json_data["username"];
    signUp.password = json_data["password"];
    signUp.email = json_data["email"];
    return signUp;
}

int JsonRequestPacketDeserializer::GetDataLenght(std::vector<unsigned char> Buffer)
{
    return int((unsigned char)(Buffer[1]) << 24 |
        (unsigned char)(Buffer[2]) << 16 |
        (unsigned char)(Buffer[3]) << 8 |
        (unsigned char)(Buffer[4]));
}

json JsonRequestPacketDeserializer::GetJson(std::vector<unsigned char> Buffer, int dataLengh)
{
    std::vector<std::uint8_t> Bdata;
    auto ptr = Buffer.begin() + START_DATA;
    int temp = dataLengh;
    while (temp > 0)
    {
        Bdata.push_back(std::uint8_t(*ptr));
        ++ptr;
        temp--;
    }
    return json::parse(Bdata);
}

