#include "GameEventObserver.h"
#include "Player.h"
#include "Room.h"
#include "Card.h"

void CGameEventObserver::registerOnPreLossBlood(bool (*PreLossBloodFunction)(CRoom * room, CPlayer * loser))
{
  if(PreLossBloodListener.find(PreLossBloodFunction) == PreLossBloodListener.end())
  {
    PreLossBloodListener[PreLossBloodFunction] = 0;
  }
  PreLossBloodListener[PreLossBloodFunction]++;
}
void CGameEventObserver::registerOnLossBlood(void (*LossBloodFunction)(CRoom * room, CPlayer * loser, CPlayer * attacker))
{
  if(LossBloodListener.find(LossBloodFunction) == LossBloodListener.end())
  {
    LossBloodListener[LossBloodFunction] = 0;
  }
  LossBloodListener[LossBloodFunction]++;
}
void CGameEventObserver::registerOnDeath(void (*DeathFunction)(CRoom * room, CPlayer * deadPerson, CPlayer * attacker))
{
  if(DeathListener.find(DeathFunction) == DeathListener.end())
  {
    DeathListener[DeathFunction] = 0;
  }
  DeathListener[DeathFunction]++;
}
void CGameEventObserver::registerOnDrawCard(bool (*DrawCardFunction)(CRoom * room, CPlayer * Drawer))
{
  if(DrawCardListener.find(DrawCardFunction) == DrawCardListener.end())
  {
    DrawCardListener[DrawCardFunction] = 0;
  }
  DrawCardListener[DrawCardFunction]++;
}
void CGameEventObserver::registerOnEquip(void (*EquipFunction)(CCard * card, CPlayer * Equiper))
{
  if(EquipListener.find(EquipFunction) == EquipListener.end())
  {
    EquipListener[EquipFunction] = 0;
  }
  EquipListener[EquipFunction]++;
}
void CGameEventObserver::registerOnUnequip(void (*UnequipFunction)(CCard * card, CPlayer * Unequiper))
{
  if(UnequipListener.find(UnequipFunction) == UnequipListener.end())
  {
    UnequipListener[UnequipFunction] = 0;
  }
  UnequipListener[UnequipFunction]++;
}
void CGameEventObserver::registerOnRoundEnd(void (*RoundEndFunction)(CRoom * room, CPlayer * RoundEnder))
{
  if(RoundEndListener.find(RoundEndFunction) == RoundEndListener.end())
  {
    RoundEndListener[RoundEndFunction] = 0;
  }
  RoundEndListener[RoundEndFunction]++;
}

bool CGameEventObserver::callPreLossBlood(CRoom * room, CPlayer * loser)
{
  bool result = true;
  for(auto i = PreLossBloodListener.begin();i != PreLossBloodListener.end();++i)
  {
    result = std::min(result, (i->first)(room, loser));
  }
  return result;
}
void CGameEventObserver::callLossBlood(CRoom * room, CPlayer * loser, CPlayer * attacker)
{
  for(auto i = LossBloodListener.begin();i != LossBloodListener.end();++i)
  {
    (i->first)(room, loser, attacker);
  }
}
void CGameEventObserver::callDeath(CRoom * room, CPlayer * deadPerson, CPlayer * attacker)
{
  for(auto i = DeathListener.begin();i != DeathListener.end();++i)
  {
    (i->first)(room, deadPerson, attacker);
  }
}
bool CGameEventObserver::callDrawCard(CRoom * room, CPlayer * Drawer)
{
  bool result = true;
  for(auto i = DrawCardListener.begin();i != DrawCardListener.end();++i)
  {
    result = std::min(result, (i->first)(room, Drawer));
  }
  return result;
}
void CGameEventObserver::callEquip(CCard * card, CPlayer * Equiper)
{
  for(auto i = EquipListener.begin();i != EquipListener.end();++i)
  {
    (i->first)(card, Equiper);
  }
}
void CGameEventObserver::callUnequip(CCard * card, CPlayer * Unequiper)
{
  for(auto i = UnequipListener.begin();i != UnequipListener.end();++i)
  {
    (i->first)(card, Unequiper);
  }
}
void CGameEventObserver::callRoundEnd(CRoom * room, CPlayer * RoundEnder)
{
  for(auto i = RoundEndListener.begin();i != RoundEndListener.end();++i)
  {
    (i->first)(room, RoundEnder);
  }
}
void CGameEventObserver::unregisterOnPreLossBlood(bool (*PreLossBloodFunction)(CRoom * room, CPlayer * loser))
{
  if(PreLossBloodListener[PreLossBloodFunction] <= 1)
  {
    PreLossBloodListener.erase(PreLossBloodFunction);
  }
  else
  {
    PreLossBloodListener[PreLossBloodFunction]--;
  }
}
void CGameEventObserver::unregisterOnLossBlood(void (*LossBloodFunction)(CRoom * room, CPlayer * loser, CPlayer * attacker))
{
  if(LossBloodListener[LossBloodFunction] <= 1)
  {
    LossBloodListener.erase(LossBloodFunction);
  }
  else
  {
    LossBloodListener[LossBloodFunction]--;
  }
}
void CGameEventObserver::unregisterOnDeath(void (*DeathFunction)(CRoom * room, CPlayer * deadPerson, CPlayer * attacker))
{
  if(DeathListener[DeathFunction] <= 1)
  {
    DeathListener.erase(DeathFunction);
  }
  else
  {
    DeathListener[DeathFunction]--;
  }
}
void CGameEventObserver::unregisterOnDrawCard(bool (*DrawCardFunction)(CRoom * room, CPlayer * Drawer))
{
  if(DrawCardListener[DrawCardFunction] <= 1)
  {
    DrawCardListener.erase(DrawCardFunction);
  }
  else
  {
    DrawCardListener[DrawCardFunction]--;
  }
}
void CGameEventObserver::unregisterOnEquip(void (*EquipFunction)(CCard * card, CPlayer * Equiper))
{
  if(EquipListener[EquipFunction] <= 1)
  {
    EquipListener.erase(EquipFunction);
  }
  else
  {
    EquipListener[EquipFunction]--;
  }
}
void CGameEventObserver::unregisterOnUnequip(void (*UnequipFunction)(CCard * card, CPlayer * Equiper))
{
  if(UnequipListener[UnequipFunction] <= 1)
  {
    UnequipListener.erase(UnequipFunction);
  }
  else
  {
    UnequipListener[UnequipFunction]--;
  }
}
void CGameEventObserver::unregisterOnRoundEnd(void (*RoundEndFunction)(CRoom * room, CPlayer * RoundEnder))
{
  if(RoundEndListener[RoundEndFunction] <= 1)
  {
    RoundEndListener.erase(RoundEndFunction);
  }
  else
  {
    RoundEndListener[RoundEndFunction]--;
  }
}
