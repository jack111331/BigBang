#include "Database.h"
#include "User.h"
#include <vector>
CDatabase::CDatabase() : conn("datas", (std::string("35.201") + std::string(".243.64")).c_str(), "root", "object-oriented")
{
}
void CDatabase::UpdateUserInfo(CUser * user)
{
  mysqlpp::Query query = conn.query();
  query << ("SELECT * FROM users WHERE user_id=" + std::to_string(user->GetID()) + ";");
  mysqlpp::StoreQueryResult ares = query.store();
  if(ares.num_rows())
  {
    user->SetName(std::string(ares[0]["username"]));

    query << ("SELECT * FROM records WHERE user_id=" + std::to_string(user->GetID()) + ";");
    ares = query.store();
    user->SetMoney(ares[0]["money"]);
    user->SetWin(ares[0]["win"]);
    user->SetLose(ares[0]["lose"]);
  }
}
void CDatabase::UpdateDBUserInfo(CUser * user)
{
  mysqlpp::Query query = conn.query();
  query << ("SELECT * FROM users WHERE user_id=" + std::to_string(user->GetID()));
  mysqlpp::StoreQueryResult ares = query.store();
  if(!ares.num_rows())
  {
    query << "Insert into users (user_id, username) values (" << std::to_string(user->GetID()) << ", \"" << user->GetName() << "\");";
    query.execute();

    query << ("Insert into records (user_id, win, lose, money) values (" + std::to_string(user->GetID()) + ", " + std::to_string(user->GetWin()) + ", " + std::to_string(user->GetLose()) + ", " + std::to_string(user->GetMoney()) + ");");
    query.execute();
  }
  else
  {
    query << ("UPDATE records SET win = " + std::to_string(user->GetWin()) + " , lose = " + std::to_string(user->GetLose()) + " , money = " + std::to_string(user->GetMoney()) + " WHERE user_id = " + std::to_string(user->GetID()) + ";");
    query.execute();
  }
}
std::vector<uint32_t> CDatabase::GetFriendList(uint32_t UserID)
{
  mysqlpp::Query query = conn.query();
  query << ("SELECT * FROM friend WHERE user_1=" + std::to_string(UserID) + " OR user_2=" + std::to_string(UserID) + ";");
  mysqlpp::StoreQueryResult ares = query.store();
  std::vector<uint32_t> Friend;
  for(size_t i = 0;i < ares.num_rows();i++)
  {
    if(static_cast<uint32_t>(ares[i]["user_1"]) == UserID)
    {
      Friend.push_back(ares[i]["user_2"]);
    }
    else
    {
      Friend.push_back(ares[i]["user_1"]);
    }
  }
  return Friend;
}
int CDatabase::InsertFriend(uint32_t UserID, uint32_t UserID_Target)
{
  mysqlpp::Query query = conn.query();
  query << ("SELECT * FROM users WHERE (user_id=" + std::to_string(UserID_Target) + ");");
  mysqlpp::StoreQueryResult ares = query.store();
  if(ares.num_rows())
  {
    query << ("SELECT * FROM friend WHERE (user_1=" + std::to_string(UserID) + " AND user_2=" + std::to_string(UserID_Target) + ") OR (user_1=" + std::to_string(UserID_Target) + " AND user_2=" + std::to_string(UserID) + ");");
    mysqlpp::StoreQueryResult ares = query.store();
    if(!ares.num_rows())
    {
      query << "Insert into friend (user_1, user_2) values (" << UserID << ", " << UserID_Target << ");";
      query.execute();
      return 1;
    }
    else
    {
      return 3;
    }
  }
  else
  {
    return 2;
  }
}
std::vector<uint32_t> CDatabase::GetExclusiveCardList(uint32_t UserID, int type)
{
  mysqlpp::Query query = conn.query();
  query << ("SELECT * FROM exclusiveCard WHERE (user_id=" + std::to_string(UserID) + " AND type=" + std::to_string(type) + ");");
  mysqlpp::StoreQueryResult ares = query.store();
  std::vector<uint32_t> ExclusiveCardList;
  for(size_t i = 0;i < ares.num_rows();i++)
  {
    ExclusiveCardList.push_back(ares[i]["card_id"]);
  }
  return ExclusiveCardList;
}
void CDatabase::InsertExclusiveCard(uint32_t UserID, int type, uint32_t CardID)
{
  mysqlpp::Query query = conn.query();
  query << "Insert into exclusiveCard (user_id, type, card_id) values (" << UserID << ", " << type << ", " << CardID << ");";
  query.execute();
}
CDatabase::~CDatabase()
{
  conn.disconnect();
}
