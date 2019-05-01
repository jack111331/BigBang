#include "GameEventObserver.h"
#include "Player.h"
#include "Room.h"

std::vector<void (*)(CRoom * room, CPlayer * loser)> CGameEventObserver::LossBloodListener;
std::vector<void (*)(CRoom * room, CPlayer * deadPerson, CPlayer * attacker)> CGameEventObserver::DeathListener;
std::vector<void (*)(CRoom * room, CPlayer * Drawer)> CGameEventObserver::DrawCardListener;

void CGameEventObserver::registerOnLossBlood(void (*LossBloodFunction)(CRoom * room, CPlayer * loser))
{
  LossBloodListener.push_back(LossBloodFunction);
}
void CGameEventObserver::registerOnDeath(void (*DeathFunction)(CRoom * room, CPlayer * deadPerson, CPlayer * attacker))
{
  DeathListener.push_back(DeathFunction);
}
void CGameEventObserver::registerOnDrawCard(void (*DrawCardFunction)(CRoom * room, CPlayer * Drawer))
{
  DrawCardListener.push_back(DrawCardFunction);
}
void CGameEventObserver::callLossBlood(CRoom * room, CPlayer * loser)
{
  for(auto i = LossBloodListener.begin();i != LossBloodListener.end();++i)
  {
    (*i)(room, loser);
  }
}
void CGameEventObserver::callDeath(CRoom * room, CPlayer * deadPerson, CPlayer * attacker)
{
  for(auto i = DeathListener.begin();i != DeathListener.end();++i)
  {
    (*i)(room, deadPerson, attacker);
  }
}
void CGameEventObserver::callDrawCard(CRoom * room, CPlayer * Drawer)
{
  for(auto i = DrawCardListener.begin();i != DrawCardListener.end();++i)
  {
    (*i)(room, Drawer);
  }
}
void CGameEventObserver::unregisterOnLossBlood(void (*LossBloodFunction)(CRoom * room, CPlayer * loser))
{
  for(auto i = LossBloodListener.begin();i != LossBloodListener.end();++i)
  {
    if(*i == LossBloodFunction)
    {
      LossBloodListener.erase(i);
    }
  }
}
void CGameEventObserver::unregisterOnDeath(void (*DeathFunction)(CRoom * room, CPlayer * deadPerson, CPlayer * attacker))
{
  for(auto i = DeathListener.begin();i != DeathListener.end();++i)
  {
    if(*i == DeathFunction)
    {
      DeathListener.erase(i);
    }
  }
}
void CGameEventObserver::unregisterOnDeath(void (*DrawCardFunction)(CRoom * room, CPlayer * Drawer))
{
  for(auto i = DrawCardListener.begin();i != DrawCardListener.end();++i)
  {
    if(*i == DrawCardFunction)
    {
      DrawCardListener.erase(i);
    }
  }
}
