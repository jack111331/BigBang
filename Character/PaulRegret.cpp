#include "PaulRegret.h"
#include <string>
#include "Player.h"
#include "Action.h"
#include "Room.h"
#include "GameEventObserver.h"


CCharacterPaul::CCharacterPaul(CRoom * room) : CCharacter(room)
{
  const std::string Name("Paul Regret");
  const std::string Feature("Add 1 attack range.");
  const int MaxHP = 3;
  const int AttackRange = 1;
  const int AddRange = 1;
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
}
CCharacterPaul::~CCharacterPaul()
{

}
