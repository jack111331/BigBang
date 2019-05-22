#include "Gatling.h"
#include <string>
#include "Room.h"
#include "Action.h"

CGatling::CGatling(CRoom * room, int number, Suit suit) : CCard(room, number, suit)
{
  const std::string Name("Gatling");
  const std::string Feature("Every other people should use Missed! to stop attack, or they will loss 1 HP.");
  SetName(Name);
  SetFeature(Feature);
}
void CGatling::UseCardEffect(CRoom * room, CPlayer * myself, CPlayer * target)
{
  std::vector<CPlayer *> PlayerList = room->GetPlayerList();
  for(std::vector<CPlayer *>::iterator it = PlayerList.begin();it != PlayerList.end();++it)
  {
    if((*it) != myself)
    {
      NSAction::Attack(room, myself, target, "Missed!");
    }
  }
  NSAction::RemoveCardToDiscardPlague(room->GetDiscardPlague(), myself, this);
}
