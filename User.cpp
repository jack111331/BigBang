#include "User.h"
#include "mysql++/mysql++.h"
#include <iostream>
CUser::CUser(CMessageMediator * mediator) : CColleague(mediator)
{
  this->mediator = mediator;
  //get data from DB
  RetriveDataFromDB();
}

void CUser::RetriveDataFromDB()
{
  mysqlpp::Connection conn(false);
  conn.connect("datas", (std::string("35.201") + std::string(".243.64")).c_str(), "root", "object-oriented");//ㄅ要打我們的資料庫QQ
  mysqlpp::Query query = conn.query();
  query << ("SELECT * FROM users WHERE user_id=" + std::to_string(this->ID) + ";");
  mysqlpp::StoreQueryResult ares = query.store();
  if(ares.num_rows())
  {
    SetName(std::string(ares[0]["username"]));

    query << ("SELECT * FROM records WHERE user_id=" + std::to_string(this->ID) + ";");
    ares = query.store();
    SetMoney(ares[0]["money"]);
    SetWin(ares[0]["win"]);
    SetLose(ares[0]["lose"]);
  }
}
void CUser::ReceiveMessage(std::string message)
{
  NSHandleMessage::HandleMessage(message.c_str(), this);
}
void CUser::SetID(uint32_t ID)
{
  this->ID = ID;
}
CPlayer * CUser::GetPlayer()
{
  return this->player;
}
std::string CUser::GetName()
{
  return this->name;
}
int CUser::GetMoney()
{
  return this->money;
}
int CUser::GetWin()
{
  return this->win;
}
int CUser::GetLose()
{
  return this->lose;
}
uint32_t CUser::GetID()
{
  return this->ID;
}
void CUser::SetPlayer(CPlayer * player)
{
  this->player = player;
}
void CUser::SetName(const std::string & name)
{
  this->name = name;
}
void CUser::SetMoney(int money)
{
  this->money = money;
}
void CUser::SetWin(int win)
{
  this->win = win;
}
void CUser::SetLose(int lose)
{
  this->lose = lose;
}
CUser::~CUser()
{
  mysqlpp::Connection conn(false);
  conn.connect("datas", (std::string("35.201") + std::string(".243.64")).c_str(), "root", "object-oriented");//ㄅ要打我們的資料庫QQ
  mysqlpp::Query query = conn.query();
  query << ("SELECT * FROM users WHERE user_id=" + std::to_string(this->ID));
  mysqlpp::StoreQueryResult ares = query.store();
  if(!ares.num_rows())
  {
    query << "Insert into users (user_id, username) values (" << std::to_string(this->ID) << ", \"" << GetName() << "\");";
    query.execute();

    query << ("Insert into records (user_id, win, lose, money) values (" + std::to_string(this->ID) + ", " + std::to_string(GetWin()) + ", " + std::to_string(GetLose()) + ", " + std::to_string(GetMoney()) + ");");
    query.execute();
  }
  else
  {
    query << ("UPDATE records SET win = " + std::to_string(GetWin()) + " , lose = " + std::to_string(GetLose()) + " , money = " + std::to_string(GetMoney()) + " WHERE user_id = " + std::to_string(this->ID) + ";");
    query.execute();
  }
}
