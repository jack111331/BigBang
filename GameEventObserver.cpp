#include "GameEventObserver.h"
#include "Player.h"
#include "Room.h"
#include "Card.h"

void CGameEventObserver::registerOnPreLossBlood(bool (*PreLossBloodFunction)(CRoom * room, CPlayer * loser))
{
  PreLossBloodListener.push_back(PreLossBloodFunction);
}
void CGameEventObserver::registerOnLossBlood(void (*LossBloodFunction)(CRoom * room, CPlayer * loser, CPlayer * attacker))
{
  LossBloodListener.push_back(LossBloodFunction);
}
void CGameEventObserver::registerOnDeath(void (*DeathFunction)(CRoom * room, CPlayer * deadPerson, CPlayer * attacker))
{
  DeathListener.push_back(DeathFunction);
}
void CGameEventObserver::registerOnDrawCard(bool (*DrawCardFunction)(CRoom * room, CPlayer * Drawer))
{
  DrawCardListener.push_back(DrawCardFunction);
}
void CGameEventObserver::registerOnEquip(void (*EquipFunction)(CCard * card, CPlayer * Equiper))
{
  EquipListener.push_back(EquipFunction);
}
void CGameEventObserver::registerOnUnequip(void (*UnequipFunction)(CCard * card, CPlayer * Unequiper))
{
  UnequipListener.push_back(UnequipFunction);
}
void CGameEventObserver::registerOnRoundEnd(void (*RoundEndFunction)(CRoom * room, CPlayer * RoundEnder))
{
  RoundEndListener.push_back(RoundEndFunction);
}

bool CGameEventObserver::callPreLossBlood(CRoom * room, CPlayer * loser)
{
  for(auto i = PreLossBloodListener.begin();i != PreLossBloodListener.end();++i)
  {
    if((*i)(room, loser) == false)
    {
      return false;
    }
  }
  return true;
}
void CGameEventObserver::callLossBlood(CRoom * room, CPlayer * loser, CPlayer * attacker)
{
  for(auto i = LossBloodListener.begin();i != LossBloodListener.end();++i)
  {
    (*i)(room, loser, attacker);
  }
}
void CGameEventObserver::callDeath(CRoom * room, CPlayer * deadPerson, CPlayer * attacker)
{
  for(auto i = DeathListener.begin();i != DeathListener.end();++i)
  {
    (*i)(room, deadPerson, attacker);
  }
}
bool CGameEventObserver::callDrawCard(CRoom * room, CPlayer * Drawer)
{
  for(auto i = DrawCardListener.begin();i != DrawCardListener.end();++i)
  {
    if((*i)(room, Drawer) == false)
    {
      return false;
    }
  }
  return true;
}
void CGameEventObserver::callEquip(CCard * card, CPlayer * Equiper)
{
  for(auto i = EquipListener.begin();i != EquipListener.end();++i)
  {
    (*i)(card, Equiper);
  }
}
void CGameEventObserver::callUnequip(CCard * card, CPlayer * Unequiper)
{
  for(auto i = UnequipListener.begin();i != UnequipListener.end();++i)
  {
    (*i)(card, Unequiper);
  }
}
void CGameEventObserver::callRoundEnd(CRoom * room, CPlayer * RoundEnder)
{
  for(auto i = RoundEndListener.begin();i != RoundEndListener.end();++i)
  {
    (*i)(room, RoundEnder);
  }
}
void CGameEventObserver::unregisterOnPreLossBlood(bool (*PreLossBloodFunction)(CRoom * room, CPlayer * loser))
{
  for(auto i = PreLossBloodListener.begin();i != PreLossBloodListener.end();++i)
  {
    if(*i == PreLossBloodFunction)
    {
      PreLossBloodListener.erase(i);
    }
  }
}
void CGameEventObserver::unregisterOnLossBlood(void (*LossBloodFunction)(CRoom * room, CPlayer * loser, CPlayer * attacker))
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
void CGameEventObserver::unregisterOnDrawCard(bool (*DrawCardFunction)(CRoom * room, CPlayer * Drawer))
{
  for(auto i = DrawCardListener.begin();i != DrawCardListener.end();++i)
  {
    if(*i == DrawCardFunction)
    {
      DrawCardListener.erase(i);
    }
  }
}
void CGameEventObserver::unregisterOnEquip(void (*EquipFunction)(CCard * card, CPlayer * Equiper))
{
  for(auto i = EquipListener.begin();i != EquipListener.end();++i)
  {
    if(*i == EquipFunction)
    {
      EquipListener.erase(i);
    }
  }
}
void CGameEventObserver::unregisterOnUnequip(void (*UnequipFunction)(CCard * card, CPlayer * Equiper))
{
  for(auto i = UnequipListener.begin();i != UnequipListener.end();++i)
  {
    if(*i == UnequipFunction)
    {
      UnequipListener.erase(i);
    }
  }
}
void CGameEventObserver::unregisterOnRoundEnd(void (*RoundEndFunction)(CRoom * room, CPlayer * RoundEnder))
{
  for(auto i = RoundEndListener.begin();i != RoundEndListener.end();++i)
  {
    if(*i == RoundEndFunction)
    {
      RoundEndListener.erase(i);
    }
  }
}
