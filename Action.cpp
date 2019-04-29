#include "Action.h"
#include "Player.h"
#include "Plague.h"
#include "GameEventObserver.h"
#include "Room.h"

namespace NSAction
{
  bool Attack(CRoom * room, CPlayer * attacker, CPlayer * attackee, std::string dodgeByCard)
  {
    if(attackee->isCardInHolding(dodgeByCard))
    {
      //invoke player to choose whether he want to use this card
    }
    else
    {
      CGameEventObserver::callAttack(room, attacker, attackee);//?????
      attackee->SetHP(attackee->GetHP()-1);
      if(attackee->GetHP() <= 0)
      {
        CGameEventObserver::callDeath(room, attackee, attacker);
      }
      return true;
    }
    return false;
  }
  void RecoverHealth(CPlayer * target, int health)
  {
    target->SetHP(std::min(target->GetHP()+health, target->GetMaxHP()));
  }
  void DrawCardFromPlague(CPlague * plague, CPlayer * drawer)
  {
    CCard * DrawedCard = plague->ChooseTopCard();
    if(DrawedCard != nullptr)
    {
      drawer->AddHolding(DrawedCard);
      plague->RemoveCardFromPlague(DrawedCard);
    }
  }
  void ChooseCardFromPlayer(CPlayer * chooser, CPlayer * choosee)
  {
    //invoke client to show choosee's holding and draw card UI
  }
  void DrawCardFromPlayer(CPlayer * drawer, CPlayer * drawee)
  {
    //invoke client to show draw card UI
  }
  void FoldCard(CPlayer * folder, CCard * card, CPlague * DiscardPlague)
  {
    DiscardPlague->InsertCardToPlague(card);
    folder->RemoveHolding(card);
  }
}
