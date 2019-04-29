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
  uint32_t getFirstUserID();
  bool searchUserInLounge(CUser * user);
  void setReady(CUser * user);
  void setUnready(CUser * user);
  void exitLounge(CUser * user);
private:
  std::vector<CUser *> userList;
  std::bitset<16> isReady;
};
