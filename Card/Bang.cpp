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
void CBang::UseCardEffect(CRoom * room, CPlayer * myself, CPlayer * target)
{
  if(room->GetDistance(myself, target) <= myself->GetAttackRange())
  {
    NSAction::Attack(room, myself, target, "Missed!");
    NSAction::RemoveCardToDiscardPlague(room->GetDiscardPlague(), myself, this);
  }
}