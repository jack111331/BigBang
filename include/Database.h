#pragma once
#include "mysql++/mysql++.h"
#include <vector>
class CUser;
class CDatabase
{
public:
  CDatabase();
  void ConnectToDatabase();
  void UpdateUserInfo(CUser * user);
  void UpdateDBUserInfo(CUser * user);
  std::vector<uint32_t> GetFriendList(uint32_t ID);
  void InsertFriend(uint32_t ID, uint32_t ID_2);
private:
  mysqlpp::Connection conn;
};