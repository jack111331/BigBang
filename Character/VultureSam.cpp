#include "VultureSam.h"
#include <string>
#include <vector>
#include "Player.h"
#include "Action.h"
#include "Room.h"
#include "GameEventObserver.h"


CCharacterSam::CCharacterSam(CRoom * room) : CCharacter(room)
{
  const std::string Name("Vulture Sam");
  const std::string Feature("When a player is dead, pick up all his holding.");
  const int MaxHP = 4;
  const int AttackRange = 1;
  const int AddRange = 0;
  const int MinusRange = 0;
  const bool HasMultiAttack = false;
  SetName(Name);
  SetFeature(Feature);
  SetID();
  SetMaxHP(MaxHP);
  SetAttackRange(AttackRange);
  SetAddRange(AddRange);
  SetMinusRange(MinusRange);
  SetMultiAttack(HasMultiAttack);
  room->GetRoomEvent()->registerOnDeath(OnDeath);
}
void CCharacterSam::OnDeath(CRoom * room, CPlayer * deadPerson, CPlayer * attacker)
{
  std::vector<CPlayer *> PlayerList = room->GetPlayerList();
  for(std::vector<CPlayer *>::iterator it = PlayerList.begin();it != PlayerList.end();++it)
  {
    if((*it)->GetCharacter()->GetName() == "Vulture Sam")
    {
      std::vector<CCard *> Holding = deadPerson->GetHolding();
      for(std::vector<CCard *>::iterator it_holding = Holding.begin();it_holding != Holding.end();++it_holding)
      {
        (*it)->AddHolding(*it_holding);
        deadPerson->RemoveHolding(*it_holding);
      }
      break;
    }
  }
}
