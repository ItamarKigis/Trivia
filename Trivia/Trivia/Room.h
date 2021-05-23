#include <string>
#include <vector>
#include "LoggedUser.h"
typedef struct RoomData
{
	unsigned int id;
	std::string name;
	unsigned int maxPlayers;
	unsigned int numOfQuestionsInGame;
	unsigned int timePerQuestion;
	unsigned int isActive;
} RoomData;

class Room
{
public:
	Room(LoggedUser user, RoomData data);
	void addUser(LoggedUser user);
	void removeUser(LoggedUser& user);
	std::vector<std::string> getAllUsers() const;
	unsigned int getRoomState() const;
	RoomData getRoomData() const;
private:
	RoomData m_metadata;
	std::vector<LoggedUser> m_users;
};