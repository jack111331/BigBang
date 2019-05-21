#include "RoseDoolan.h"
#include <string>
#include "Player.h"
#include "Action.h"
#include "Room.h"
#include "GameEventObserver.h"


CCharacterRose::CCharacterRose(CRoom * room) : CCharacter(room)
{
  const std::string Name("Rose Doolan");
  const std::string Feature("minus 1 opposite attack range.");
  const int MaxHP = 4;
  const int AttackRange = 1;
  const int AddRange = 0;
  const int MinusRange = 1;
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
CCharacterRose::~CCharacterRose()
{

}
