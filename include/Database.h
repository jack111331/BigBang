#pragma once
#include "mysql++/mysql++.h"
#include <vector>
class CUser;
class CDatabase
{
public:
  CDatabase();
  void UpdateUserInfo(CUser * user);
  void UpdateDBUserInfo(CUser * user);
  std::vector<uint32_t> GetFriendList(uint32_t UserID);
  int InsertFriend(uint32_t UserID, uint32_t UserID_2);
  std::vector<uint32_t> GetExclusiveCardList(uint32_t UserID, int type);
  void InsertExclusiveCard(uint32_t UserID, int type, uint32_t CardID);
  ~CDatabase();
private:
  mysqlpp::Connection conn;
};
