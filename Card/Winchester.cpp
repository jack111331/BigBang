#include "Winchester.h"
#include <string>
#include "../Room.h"

CWinchester::CWinchester()
{
  const std::string Name("Winchester");
  const std::string Feature("Attack range increased to 5.");
  constexpr int Number = 8;
  constexpr Suit suit = Suit::Spade;
  SetName(Name);
  SetFeature(Feature);
  SetNumber(Number);
  SetSuit(suit);

  constexpr bool multiAttack = 0;
  constexpr int attackRange = 5;
  SetMultiAttack(multiAttack);
  SetAttackRange(attackRange);
}
void CWinchester::UseCardEffect(CRoom * room, CPlayer * myself, CPlayer * target)
{
  //No any effect
}
