#pragma once
#include <string>
#include <vector>
#include <mutex>
#include "LoggedUser.h"
#include "RoomData.h"

class Room
{
public:
	Room();
	Room(const Room& other);
	~Room();
	Room(LoggedUser user, RoomData data);
	void addUser(LoggedUser user);
	void removeUser(LoggedUser user);
	std::vector<std::string> getAllUsers() const;
	unsigned int getRoomState() const;
	RoomData getRoomData() const;
	Room& operator=(const Room& other);
private:
	RoomData m_metadata;
	std::vector<LoggedUser> m_users;
	std::mutex _usersMutex;
	std::unique_lock<std::mutex> _usersLocker;
};