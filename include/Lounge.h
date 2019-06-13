#pragma once
#include <vector>
#include <map>
#include <stdint.h>
#include <thread>
#include "User.h"

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
  bool searchUserInLounge(uint32_t ID);
  bool isAllReady();
  bool getReadyState(CUser * user);
  void setReadyState(CUser * user, bool state);
  void exitLounge(CUser * user);
  CRoom * getRoom();
  bool startGame();
  bool getEnableExclusiveCard() const;
  void setEnableExclusiveCard(bool enable);
  ~CLounge();
private:
  std::vector<CUser *> userList;
  std::map<CUser *, bool> readyMap;
  CRoom * room;
  std::thread GameLoopThread;
  bool EnableExclusiveCard = false;
  CUser * RoomOwner; // Owner is for when all user ready, who will decide the game will start
};
