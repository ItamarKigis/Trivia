#include <vector>
#include <string>
static class JsonRequestPacketDeserializer
{
public:
	LoginRequest deserializeLoginRequest(std::vector<unsigned char>Buffer);
	SignupRequest deserializeSignupRequest(std::vector<unsigned char>Buffer);
};
struct LoginRequest
{
public:
	std::string username;
	std::string password;
};
struct SignupRequest
{
public:
	std::string username;
	std::string password;
	std::string email;
};