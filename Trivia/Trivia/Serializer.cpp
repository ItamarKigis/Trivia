 #include "Serializer.h"
 #include <bitset>

 using json = nlohmann::json;
 #define FOUR_BYTES 32
 #define BYTE 8
 #define BINARY 2

 std::array<unsigned char, 4> JsonResponsePacketSerializer::intToBytes(int paramInt)
 {
     std::array<unsigned char, 4> arrayOfByte;
     for (int i = 0; i < 4; i++)
         arrayOfByte[3 - i] = (paramInt >> (i * BYTE));
     return arrayOfByte;
 }

 void JsonResponsePacketSerializer::valsToVector(std::vector<unsigned char>& pack, json& j)
 {
     std::array<unsigned char, 4> sizeOfJson = intToBytes(sizeof(j));
     std::array<unsigned char, 4> jsonMsg = intToBytes(stoi(j.dump()));
     pack.insert(pack.begin(), sizeOfJson.begin(), sizeOfJson.end());
     pack.insert(pack.begin(), jsonMsg.begin(), jsonMsg.end());
 }

 std::vector<unsigned char> JsonResponsePacketSerializer::serializeResponse(ErrorResponse response)
 {
     std::vector<unsigned char> pack;
     json j;
     j["message"] = response.message;
     pack.push_back((int)CODES::ERROR_CODE);
     valsToVector(pack, j);
     return pack;
 }

 std::vector<unsigned char> JsonResponsePacketSerializer::serializeResponse(LoginResponse response)
 {
     std::vector<unsigned char> pack;
     json j;
     j["status"] = response.status;
     pack.push_back((int)CODES::LOGIN);
     valsToVector(pack, j);
     return pack;
 }

 std::vector<unsigned char> JsonResponsePacketSerializer::serializeResponse(SignupResponse response)
 {
     std::vector<unsigned char> pack;
     json j;
     j["status"] = response.status;
     pack.push_back((int)CODES::SIGN_UP);
     valsToVector(pack, j);
     return pack;
 }
