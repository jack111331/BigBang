#pragma once
#include <vector>
#include "Player.h"
class CRoom;
class CCard;
typedef bool (*PreLossBloodFunction)(CRoom *, CPlayer *);
typedef void (*LossBloodFunction)(CRoom *, CPlayer *, CPlayer *);
typedef void (*DeathFunction)(CRoom *, CPlayer *, CPlayer *);
typedef bool (*DrawCardFunction)(CRoom *, CPlayer *);
typedef void (*EquipFunction)(CCard *, CPlayer *);
typedef void (*UnequipFunction)(CCard *, CPlayer *);
typedef void (*RoundEndFunction)(CRoom *, CPlayer *);
class CGameEventObserver
{
public:
  void registerOnPreLossBlood(bool (*PreLossBloodFunction)(CRoom * room, CPlayer * loser));
  void registerOnLossBlood(void (*LossBloodFunction)(CRoom * room, CPlayer * loser, CPlayer * attacker));
  void registerOnDeath(void (*DeathFunction)(CRoom * room, CPlayer * deadPerson, CPlayer * attacker));
  void registerOnDrawCard(bool (*DrawCardFunction)(CRoom * room, CPlayer * Drawer));
  void registerOnEquip(void (*EquipFunction)(CCard * card, CPlayer * Equiper));
  void registerOnUnequip(void (*UnequipFunction)(CCard * card, CPlayer * Unequiper));
  void registerOnRoundEnd(void (*RoundEndFunction)(CRoom * room, CPlayer * RoundEnder));
  bool callPreLossBlood(CRoom * room, CPlayer * loser);
  void callLossBlood(CRoom * room, CPlayer * loser, CPlayer * attacker);
  void callDeath(CRoom * room, CPlayer * deadPerson, CPlayer * attacker);
  bool callDrawCard(CRoom * room, CPlayer * Drawer);
  void callEquip(CCard * card, CPlayer * Equiper);
  void callUnequip(CCard * card, CPlayer * Unequiper);
  void callRoundEnd(CRoom * room, CPlayer * RoundEnder);
  void unregisterOnPreLossBlood(bool (*PreLossBloodFunction)(CRoom * room, CPlayer * loser));
  void unregisterOnLossBlood(void (*LossBloodFunction)(CRoom * room, CPlayer * loser, CPlayer * attacker));
  void unregisterOnDeath(void (*DeathFunction)(CRoom * room, CPlayer * deadPerson, CPlayer * attacker));
  void unregisterOnDrawCard(bool (*DrawCardFunction)(CRoom * room, CPlayer * Drawer));
  void unregisterOnEquip(void (*EquipFunction)(CCard * card, CPlayer * Equiper));
  void unregisterOnUnequip(void (*UnequipFunction)(CCard * card, CPlayer * Unequiper));
  void unregisterOnRoundEnd(void (*RoundEndFunction)(CRoom * room, CPlayer * RoundEnder));
private:
  std::vector<PreLossBloodFunction> PreLossBloodListener;
  std::vector<LossBloodFunction> LossBloodListener;
  std::vector<DeathFunction> DeathListener;
  std::vector<DrawCardFunction> DrawCardListener;
  std::vector<EquipFunction> EquipListener;
  std::vector<UnequipFunction> UnequipListener;
  std::vector<RoundEndFunction> RoundEndListener;
};
