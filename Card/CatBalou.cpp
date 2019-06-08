#include "CatBalou.h"
#include <string>
#include "Room.h"
#include "Action.h"
#include "DrawCardFactory.h"
#include "User.h"
#include "WrapInfo.h"

CCatBalou::CCatBalou(CRoom * room, int number, Suit suit) : CCard(room, number, suit)
{
  const std::string Name("Cat Balou");
  const std::string Feature("Discard one card from one player.");
  SetName(Name);
  SetFeature(Feature);
}
bool CCatBalou::UseCardEffect(CRoom * room, CPlayer * myself, CPlayer * target)
{
  myself->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapShowCard(myself, target).dump());
  target->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapShowCard(myself, target).dump());
  myself->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapChooseCard(myself, target, false).dump());
  NSAction::RemoveCardToDiscardPlague(room->GetDiscardPlague(), myself, this);
  return true;
}
