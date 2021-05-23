#include "RoomManager.h"

void RoomManager::createRoom(LoggedUser user, RoomData data)
{
	m_rooms[data.id] = Room(user, data);
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
