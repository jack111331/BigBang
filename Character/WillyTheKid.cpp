#include "WillyTheKid.h"
#include <string>
#include "Player.h"
#include "Action.h"
#include "Room.h"
#include "GameEventObserver.h"


CCharacterWilly::CCharacterWilly(CRoom * room) : CCharacter(room)
{
  const std::string Name("Willy The Kid");
  const std::string Feature("Add 1 attack range.");
  const int MaxHP = 4;
  const int AttackRange = 1;
  const int AddRange = 0;
  const int MinusRange = 0;
  const bool HasMultiAttack = true;
  SetName(Name);
  SetFeature(Feature);
  SetID();
  SetMaxHP(MaxHP);
  SetAttackRange(AttackRange);
  SetAddRange(AddRange);
  SetMinusRange(MinusRange);
  SetMultiAttack(HasMultiAttack);
}
CCharacterWilly::~CCharacterWilly()
{

}
