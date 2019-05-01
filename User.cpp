#include "User.h"

CUser::CUser()
{
  //get data from DB
}

void CUser::RetriveDataFromDB()
{

}
void CUser::SetID(uint32_t ID)
{
  this->ID = ID;
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
