#include "Saloon.h"
#include <string>
#include "Room.h"
#include "GameEventObserver.h"
#include "Action.h"
#include <vector>

CSaloon::CSaloon(CRoom * room, int number, Suit suit) : CCard(room, number, suit)
{
  const std::string Name("Saloon");
  const std::string Feature("Recover all alived player 1 HP.");
  SetName(Name);
  SetFeature(Feature);
}
void CSaloon::UseCardEffect(CRoom * room, CPlayer * myself, CPlayer * target)
{
  std::vector<CPlayer *> PlayerList = room->GetPlayerList();
  for(std::vector<CPlayer *>::iterator it = PlayerList.begin();it != PlayerList.end();++it)
  {
    if(!(*it)->isDead())
    {
      NSAction::RecoverHealth(*it, 1);
    }
  }
  NSAction::RemoveCardToDiscardPlague(room->GetDiscardPlague(), myself, this);
}
