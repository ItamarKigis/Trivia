#include "RoomManager.h"

void RoomManager::createRoom(LoggedUser user, RoomData data)
{
	m_rooms[data.id] = Room(user, data);
	CurrentRoomId++;
}

void RoomManager::deleteRoom(int ID)
{
	m_rooms.erase(ID);
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
		it->second.removeUser(user);
		++it;
	}
}
