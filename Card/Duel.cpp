#include "Duel.h"
#include <string>
#include "Room.h"
#include "Action.h"

CDuel::CDuel(CRoom * room, int number, Suit suit) : CCard(room, number, suit)
{
  const std::string Name("Duel");
  const std::string Feature("The Duelee first and Dueler second, round robin to use their Bang!, if one side has no Bang! remain, then he will loss 1 HP.");
  SetName(Name);
  SetFeature(Feature);
}
bool CDuel::UseCardEffect(CRoom * room, CPlayer * myself, CPlayer * target)
{
  if(!target->isDead())
  {
    NSAction::RemoveCardToDiscardPlague(room->GetDiscardPlague(), myself, this);
    int MyTurn = 0;
    bool isEnd = 0;
    while(!isEnd)
    {
      isEnd = std::max(isEnd, NSAction::Attack(room, MyTurn?target:myself, MyTurn?myself:target, "Bang!"));
      MyTurn ^= 1;
    }
    return true;
  }
  return false;
}
