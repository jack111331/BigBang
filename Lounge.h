#pragma once
#include <vector>
#include <map>
#include <stdint.h>
#include <thread>

class CUser;
class CRoom;

class CLounge
{
public:
  CLounge();
  void joinLounge(CUser * user);
  int getLoungeSize();
  CUser * getFirstUser();
  std::vector<CUser *> & GetAllUser();
  void changeRoomOwner(CUser * user);
  CUser * getRoomOwner();
  bool searchUserInLounge(CUser * user);
  bool isAllReady();
  void setReadyState(CUser * user, bool state);
  void exitLounge(CUser * user);
  bool startGame();
private:
  std::vector<CUser *> userList;
  std::map<CUser *, bool> readyMap;
  CRoom * room;
  std::thread GameLoopThread;
  CUser * RoomOwner; // Owner is for when all user ready, who will decide the game will start
};
