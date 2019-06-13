#include "User.h"
#include "Database.h"
CUser::CUser(CMessageMediator * mediator) : CColleague(mediator)
{
  this->mediator = mediator;
}

void CUser::RetriveDataFromDB()
{
  CDatabase DB;
  DB.UpdateUserInfo(this);
  this->ExclusiveCardInventory = new CExclusiveCardInventory(this);
}
void CUser::ReceiveMessage(std::string message)
{
  std::thread Thread = std::thread(NSHandleMessage::HandleMessage, message, this);
  Thread.detach();
}
void CUser::SetID(uint32_t ID)
{
  this->ID = ID;
}
CPlayer * CUser::GetPlayer()
{
  return this->player;
}
CExclusiveCardInventory * CUser::GetExclusiveCardInventory() const
{
  return this->ExclusiveCardInventory;
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
void CUser::UpdateUserInfo()
{
  if(!name.empty())
  {
    CDatabase DB;
    DB.UpdateDBUserInfo(this);
  }
}
CUser::~CUser()
{
  UpdateUserInfo();
}
