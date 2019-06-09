#include "Panic.h"
#include <string>
#include "Room.h"
#include "Action.h"
#include "DrawCardFactory.h"
CPanic::CPanic(CRoom * room, int number, Suit suit) : CCard(room, number, suit)
{
  const std::string Name("Panic!");
  const std::string Feature("Choose one card of one player whose distance between you under 1.");
  SetName(Name);
  SetFeature(Feature);
}
bool CPanic::UseCardEffect(CRoom * room, CPlayer * myself, CPlayer * target)
{
  if(room->GetDistance(myself, target) <= 1)
  {
    NSAction::RemoveCardToDiscardPlague(room->GetDiscardPlague(), myself, this);
    CDrawCardFromPlayer * DrawCard = new CDrawCardFromPlayer(NSDrawCardFactory::DrawCard("Choose Card"));
    DrawCard->DrawCardFromPlayer(myself, target);
    delete DrawCard;
    return true;
  }
  return false;
}
