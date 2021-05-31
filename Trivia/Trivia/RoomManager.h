#pragma once
#include "Room.h"
#include <map>
#include <mutex>

class RoomManager
{
public:
	RoomManager();
	~RoomManager();
	void createRoom(LoggedUser user, RoomData data);
	void deleteRoom(int ID);
	unsigned int getRoomState(int ID);
	std::vector<RoomData> getRooms();

	Room getRoom(int ID);
	int CurrentRoomId;
	void deleteUser(LoggedUser user);
private:
	std::map<unsigned int, Room> m_rooms;
	std::mutex _roomsMutex;
	std::unique_lock<std::mutex> _roomsLocker;
};