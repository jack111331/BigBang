#include "SuzyLafayette.h"
#include <string>
#include "Player.h"
#include "Action.h"
#include "Room.h"
#include "GameEventObserver.h"


CCharacterLafayette::CCharacterLafayette(CRoom * room) : CCharacter(room)
{
  const std::string Name("Suzy Lafayette");
  const std::string Feature("When inactive, draw one card from plague.");
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
  room->GetRoomEvent()->registerOnRoundEnd(OnRoundEnd);
}
void CCharacterLafayette::OnRoundEnd(CRoom * room, CPlayer * RoundEnder)
{
  if(RoundEnder->GetCharacter()->GetName() == "Suzy Lafayette")
  {
    if(!RoundEnder->GetHoldingAmount())
    {
      NSAction::DrawCardFromPlague(room->GetPlague(), RoundEnder);
    }
  }
}
CCharacterLafayette::~CCharacterLafayette()
{

}
