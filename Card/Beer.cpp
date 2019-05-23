#include "Beer.h"
#include <string>
#include "Room.h"
#include "Action.h"
#include "GameEventObserver.h"

CBeer::CBeer(CRoom * room, int number, Suit suit) : CCard(room, number, suit)
{
  const std::string Name("Beer");
  const std::string Feature("On your turn, drink beer to recover 1 HP under Max HP. Not on your turn, when you are about to die, drink it immediately.");
  SetName(Name);
  SetFeature(Feature);
  room->GetRoomEvent()->registerOnLossBlood(OnLossBlood);
}
void CBeer::UseCardEffect(CRoom * room, CPlayer * myself, CPlayer * target)
{
  NSAction::RecoverHealth(myself, 1);
  NSAction::RemoveCardToDiscardPlague(room->GetDiscardPlague(), myself, this);
}
void CBeer::OnLossBlood(CRoom * room, CPlayer * loser, CPlayer * attacker)
{
  CCard * Beer = loser->GetCardInHolding("Beer");
  if(Beer && loser->GetHP() == 1 && room->GetAlivePlayer() > 2)
  {
    Beer->UseCardEffect(room, loser, nullptr);
  }
}
