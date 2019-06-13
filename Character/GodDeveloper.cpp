#include "GodDeveloper.h"
#include <string>
#include "Player.h"
#include "Action.h"
#include "Room.h"


CCharacterGod::CCharacterGod(CRoom * room) : CCharacter(room)
{
  const std::string Name("God Developer");
  const std::string Feature("No Effect, just have more HP and multi attack(?.");
  const int MaxHP = 6;
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
