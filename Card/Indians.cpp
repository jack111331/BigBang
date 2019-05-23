#include "Indians.h"
#include <string>
#include "Room.h"
#include "Action.h"

CIndians::CIndians(CRoom * room, int number, Suit suit) : CCard(room, number, suit)
{
  const std::string Name("Indians!");
  const std::string Feature("Every other people should use Bang! to stop attack, or they will loss 1 HP.");
  SetName(Name);
  SetFeature(Feature);
}
void CIndians::UseCardEffect(CRoom * room, CPlayer * myself, CPlayer * target)
{
  std::vector<CPlayer *> PlayerList = room->GetPlayerList();
  for(std::vector<CPlayer *>::iterator it = PlayerList.begin();it != PlayerList.end();++it)
  {
    if((*it) != myself)
    {
      NSAction::Attack(room, myself, target, "Bang!");
    }
  }
  NSAction::RemoveCardToDiscardPlague(room->GetDiscardPlague(), myself, this);
}
