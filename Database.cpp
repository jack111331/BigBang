#include "Database.h"
#include "User.h"
#include <vector>
CDatabase::CDatabase() : conn(false)
{

}
void CDatabase::ConnectToDatabase()
{
  conn.connect("datas", (std::string("35.201") + std::string(".243.64")).c_str(), "root", "object-oriented");//ㄅ要打我們的資料庫QQ
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
std::vector<uint32_t> CDatabase::GetFriendList(uint32_t ID)
{
  mysqlpp::Query query = conn.query();
  query << ("SELECT * FROM friend WHERE user_1=" + std::to_string(ID) + " OR user_2=" + std::to_string(ID) + ";");
  mysqlpp::StoreQueryResult ares = query.store();
  std::vector<uint32_t> Friend;
  for(size_t i = 0;i < ares.num_rows();i++)
  {
    if(static_cast<uint32_t>(ares[i]["user_1"]) == ID)
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
void CDatabase::InsertFriend(uint32_t ID, uint32_t ID_2)
{
  mysqlpp::Query query = conn.query();
  query << ("SELECT * FROM friend WHERE (user_1=" + std::to_string(ID) + " AND user_2=" + std::to_string(ID_2) + ") OR (user_1=" + std::to_string(ID_2) + " AND user_2=" + std::to_string(ID) + ");");
  mysqlpp::StoreQueryResult ares = query.store();
  if(!ares.num_rows())
  {
    query << "Insert into friend (user_1, user_2) values (" << ID << ", " << ID_2 << ");";
    query.execute();
  }
}
