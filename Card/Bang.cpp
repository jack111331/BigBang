#include "Bang.h"
#include <string>
#include "Room.h"
#include "Action.h"

CBang::CBang(CRoom * room, int number, Suit suit) : CCard(room, number, suit)
{
  const std::string Name("Bang!");
  const std::string Feature("Attack one player 1 HP.");
  SetName(Name);
  SetFeature(Feature);
}
bool CBang::UseCardEffect(CRoom * room, CPlayer * myself, CPlayer * target)
{
  if(!target->isDead() && room->GetDistance(myself, target) <= myself->GetAttackRange() && !myself->isAttacked())
  {
    NSAction::RemoveCardToDiscardPlague(room->GetDiscardPlague(), myself, this);
    NSAction::Attack(room, myself, target, "Missed!");
    if(!myself->isHasMultiAttack())
    {
      myself->SetAttacked(true);
    }
    return true;
  }
  return false;
}
