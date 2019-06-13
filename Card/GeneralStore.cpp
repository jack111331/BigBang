#include "GeneralStore.h"
#include <string>
#include "Room.h"
#include "GameEventObserver.h"
#include "Action.h"
#include <vector>
#include "User.h"
#include "WrapInfo.h"

CGeneralStore::CGeneralStore(CRoom * room, int number, Suit suit) : CCard(room, number, suit)
{
  const std::string Name("General Store");
  const std::string Feature("Draw alive amount player card and distribute them to every player, start from yourself.");
  SetName(Name);
  SetFeature(Feature);
}
bool CGeneralStore::UseCardEffect(CRoom * room, CPlayer * myself, CPlayer * target)
{
  NSAction::RemoveCardToDiscardPlague(room->GetDiscardPlague(), myself, this);
  int DrawCardAmount = room->GetAlivePlayer();
  std::vector<CCard *> ChooseCardList;
  for(int i = 0;i < DrawCardAmount;i++)
  {
    CCard * card;
    if(room->GetPlague()->GetPlagueCardAmount() - i <= 0)
    {
      card = room->GetPlague()->ChooseTopCard();
    }
    else
    {
      card = room->GetDiscardPlague()->ChooseTopCard();
    }
    ChooseCardList.push_back(card);
  }
  CPlayer * CurrentPlayer;
  for(CurrentPlayer = myself;room->GetNextPlayer(CurrentPlayer) != myself;CurrentPlayer = room->GetNextPlayer(CurrentPlayer))
  {
    CurrentPlayer->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapChooseCardInfo(ChooseCardList).dump());
    int choice = CurrentPlayer->BusyWaiting(29);
    for(std::vector<CCard *>::iterator it = ChooseCardList.begin();it != ChooseCardList.end();++it)
    {
      if((*it)->GetID() == choice)
      {
        ChooseCardList.erase(it);
        break;
      }
    }
  }
  return true;
}
