#include "Room.h"

Room::Room()
{
	_usersLocker = std::unique_lock<std::mutex>(_usersMutex, std::defer_lock);
}

Room::Room(const Room& other)
{
	m_metadata = other.m_metadata;
	m_users = other.m_users;
}

Room::~Room()
{
}

Room::Room(LoggedUser user, RoomData data) : m_metadata(data)
{
	_usersLocker.lock();
	m_users.push_back(user);
	_usersLocker.unlock();
}

void Room::addUser(LoggedUser user)
{
	_usersLocker.lock();
	m_users.push_back(user);
	_usersLocker.unlock();
}

void Room::removeUser(LoggedUser user)
{
	_usersLocker.lock();
	m_users.erase(std::remove(m_users.begin(), m_users.end(), user), m_users.end());
	_usersLocker.unlock();
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
