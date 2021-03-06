#pragma once
#include <map>
#include <stdint.h>
#include "Lounge.h"

class CUser;
//Singleton
class CLoungeManage
{
public:
  static CLoungeManage * getInstance();
  void addUserToNewLounge(CUser * user);
  void addUserToLounge(CUser * user, uint32_t ID);
  uint32_t searchLoungeNumber(CUser * user);
  uint32_t searchLoungeByUserID(uint32_t ID);
  CLounge * searchLounge(CUser * user);
  CLounge * searchLounge(uint32_t ID);
  void removeUserFromLounge(CUser * user);
  const std::map<uint32_t, CLounge *> & GetLoungeSet();
  ~CLoungeManage();
  static CLoungeManage * instance;
private:
  std::map<uint32_t, CLounge *> loungeSet;
};
