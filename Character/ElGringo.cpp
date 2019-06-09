#include "ElGringo.h"
#include <string>
#include "Player.h"
#include "Action.h"
#include "Room.h"
#include "GameEventObserver.h"


CCharacterGringo::CCharacterGringo(CRoom * room) : CCharacter(room)
{
  const std::string Name("El Gringo");
  const std::string Feature("When loss blood, draw one card from attacker.");
  const int MaxHP = 3;
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
  room->GetRoomEvent()->registerOnLossBlood(OnLossBlood);
}
void CCharacterGringo::OnLossBlood(CRoom * room, CPlayer * loser, CPlayer * attacker)
{
  if(loser->GetCharacter()->GetName() == "El Gringo")
  {
    CDrawCardFromPlayer * DrawCardStrategy = new CDrawCardFromPlayer(NSDrawCardFactory::DrawCard("Random Choose Card"));
    DrawCardStrategy->DrawCardFromPlayer(loser, attacker);
    delete DrawCardStrategy;
  }
}
CCharacterGringo::~CCharacterGringo()
{
  GetInRoom()->GetRoomEvent()->unregisterOnLossBlood(OnLossBlood);
}
