#pragma once
#include <bitset>
#include <vector>
#include <stdint.h>

class CUser;

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
  void setReady(CUser * user);
  void setUnready(CUser * user);
  void exitLounge(CUser * user);
private:
  std::vector<CUser *> userList;
  std::bitset<16> isReady;
  CUser * RoomOwner; // Owner is for when all user ready, who will decide the game will start
};
