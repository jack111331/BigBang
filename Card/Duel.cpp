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
void CDuel::UseCardEffect(CRoom * room, CPlayer * myself, CPlayer * target)
{
  int MyTurn = 0;
  bool isEnd = 0;
  while(!isEnd)
  {
    isEnd = max(isEnd, NSAction::Attack(room, MyTurn?target:myself, Myturn?myself:target, "Bang!"));
    Myturn ^= 1;
  }
  NSAction::RemoveCardToDiscardPlague(room->GetDiscardPlague(), myself, this);
}
