#include "Room.h"

Room::Room(LoggedUser user, RoomData data) : m_metadata(data)
{
	m_users.push_back(user);
}

void Room::addUser(LoggedUser user)
{
	m_users.push_back(user);
}

void Room::removeUser(LoggedUser user)
{
	std::remove(m_users.begin(), m_users.end(), user);
}

std::vector<std::string> Room::getAllUsers() const
{
	std::vector<std::string> users;
	auto it = m_users.begin();
	while (it != m_users.end())
	{
		users.push_back(it->getUsername());
		++it;
	}
	return users;
}

unsigned int Room::getRoomState() const
{
	return m_metadata.isActive;
}

RoomData Room::getRoomData() const
{
	return m_metadata;
}
