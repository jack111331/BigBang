#include "User.h"

CUser::CUser(CMessageMediator * mediator) : CColleague(mediator)
{
  this->mediator = mediator;
  //get data from DB
}

void CUser::RetriveDataFromDB()
{

}
void CUser::ReceiveMessageAndUpdate(const std::string & message)
{
  NSHandleMessage::HandleMessage(message.c_str(), this);
}
void CUser::SetID(uint32_t ID)
{
  this->ID = ID;
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
CUser::~CUser()
{

}
