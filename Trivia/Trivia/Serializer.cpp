 #include "Serializer.h"
 #include "json.hpp"

 using json = nlohmann::json;
 #define FIRST 1s
 #define BYTE 8
 #define BINARY 2

 std::array<unsigned char, 4> JsonResponsePacketSerializer::intToBytes(int paramInt)
 {
     std::array<unsigned char, 4> arrayOfByte;
     for (int i = 0; i < 4; i++)
         arrayOfByte[3 - i] = (paramInt >> (i * BYTE));
     return arrayOfByte;
 }

 void JsonResponsePacketSerializer::valsToVector(std::vector<unsigned char>& pack, const int size, const std::string jsonData)
 {
     std::array<unsigned char, 4> sizeOfJson = intToBytes(size);
     pack.insert(pack.begin() + 1, sizeOfJson.begin(), sizeOfJson.end()); //start at sec place
     pack.insert(pack.begin() + 5, jsonData.begin(), jsonData.end());
 }

 std::vector<unsigned char> JsonResponsePacketSerializer::serializeResponse(ErrorResponse response)
 {
     std::vector<unsigned char> pack;
     json j;
     j["message"] = response.message;
     pack.push_back((int)CODES::ERROR_CODE);
     valsToVector(pack, j.size(), j.dump());
     return pack;
 }

 std::vector<unsigned char> JsonResponsePacketSerializer::serializeResponse(LoginResponse response)
 {
     std::vector<unsigned char> pack;
     json j;
     j["status"] = response.status;
     pack.push_back((int)CODES::LOGIN);
     valsToVector(pack, j.size(), j.dump());
     return pack;
 }

 std::vector<unsigned char> JsonResponsePacketSerializer::serializeResponse(SignupResponse response)
 {
     std::vector<unsigned char> pack;
     json j;
     j["status"] = response.status;
     pack.push_back((int)CODES::SIGN_UP);
     valsToVector(pack, j.size(), j.dump());
     return pack;
 }
