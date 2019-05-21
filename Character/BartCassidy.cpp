#include "BartCassidy.h"
#include <string>
#include "Player.h"
#include "GameEventObserver.h"
#include "Action.h"
#include "Room.h"


CCharacterBart::CCharacterBart(CRoom * room) : CCharacter(room)
{
  const std::string Name("Bart Cassidy");
  const std::string Feature("Draw one card from plague while HP decrease one point.");
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
  GetInRoom()->GetRoomEvent()->registerOnLossBlood(OnLossBlood);
}
void CCharacterBart::OnLossBlood(CRoom * room, CPlayer * loser, CPlayer * attacker)
{
  //it need room to get plague
  if(loser->GetCharacter()->GetName() == "Bart Cassidy")
  {
    NSAction::DrawCardFromPlague(room->GetPlague(), loser);
  }
}
CCharacterBart::~CCharacterBart()
{
  GetInRoom()->GetRoomEvent()->unregisterOnLossBlood(OnLossBlood);
}
