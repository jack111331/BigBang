#pragma once
#include <map>
#include <stdint.h>
#include "Lounge.h"

class CUser;

class CLoungeManage
{
public:
  CLoungeManage();
  void addUserToNewLounge(CUser * user);
  void addUserToLounge(CUser * user, uint32_t ID);
  uint32_t searchLounge(CUser * user);
  void removeUserFromLounge(CUser * user);
  ~CLoungeManage();
private:
  std::map<uint32_t, CLounge *> loungeSet;
};
