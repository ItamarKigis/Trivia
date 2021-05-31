#include "RoomManager.h"

RoomManager::RoomManager()
{
	_roomsLocker = std::unique_lock<std::mutex>(_roomsMutex, std::defer_lock);
}

RoomManager::~RoomManager()
{
}

void RoomManager::createRoom(LoggedUser user, RoomData data)
{
	_roomsLocker.lock();
	m_rooms[data.id] = Room(user, data);
	CurrentRoomId++;
	_roomsLocker.unlock();
}

void RoomManager::deleteRoom(int ID)
{
	_roomsLocker.lock();
	m_rooms.erase(ID);
	_roomsLocker.unlock();
}

unsigned int RoomManager::getRoomState(int ID)
{
	try
	{
		return m_rooms[ID].getRoomState();
	}
	catch (std::exception& e)
	{
		return NULL;
	}
}

std::vector<RoomData> RoomManager::getRooms()
{
	std::vector<RoomData> data;
	auto it = m_rooms.begin();
	while(it != m_rooms.end())
	{
		data.push_back(it->second.getRoomData());
		++it;
	}
	return data;
}

Room RoomManager::getRoom(int ID)
{
	return m_rooms[ID];
}

void RoomManager::deleteUser(LoggedUser user)
{
	std::map<unsigned int, Room>::iterator it = m_rooms.begin();
	while (it != m_rooms.end())
	{
		_roomsLocker.lock();
		it->second.removeUser(user);
		_roomsLocker.unlock();
		++it;
	}
}
