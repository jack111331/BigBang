#pragma once
#include <vector>
#include <map>
#include <stdint.h>

class CUser;
class CRoom;

class CLounge
{
public:
  CLounge();
  void joinLounge(CUser * user);
  int loungeSize();
  CUser * getFirstUser();
  void changeRoomOwner(CUser * user);
  CUser * getRoomOwner();
  bool searchUserInLounge(CUser * user);
  bool isAllReady();
  void setReady(CUser * user);
  void setUnready(CUser * user);
  void exitLounge(CUser * user);
  bool startGame();
private:
  std::vector<CUser *> userList;
  std::map<CUser *, bool> readyMap;
  CRoom * room;
  CUser * RoomOwner; // Owner is for when all user ready, who will decide the game will start
};
