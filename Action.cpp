#include "Action.h"
#include "Player.h"
#include "Plague.h"
#include "GameEventObserver.h"
#include "InvokeMessage.h"
#include "Room.h"

bool NSAction::Attack(CRoom * room, CPlayer * attacker, CPlayer * attackee, std::string dodgeByCard)
{
  CCard * HoldingRevoltCard = attackee->GetCardInHolding(dodgeByCard);
  if(HoldingRevoltCard != nullptr)
  {
    //invoke player to choose whether he want to use this card
    bool Revolt = NSInvokeMessage::InvokeRevolt(attackee, HoldingRevoltCard);
    if(Revolt)
    {
      attackee->RemoveHolding(HoldingRevoltCard);
      return false;
    }
    else
    {
      CGameEventObserver::callLossBlood(room, attackee);
      attackee->SetHP(attackee->GetHP()-1);
      if(attackee->GetHP() <= 0)
      {
        CGameEventObserver::callDeath(room, attackee, attacker);
      }
      return true;
    }
  }
  else
  {
    CGameEventObserver::callLossBlood(room, attackee);
    attackee->SetHP(attackee->GetHP()-1);
    if(attackee->GetHP() <= 0)
    {
      CGameEventObserver::callDeath(room, attackee, attacker);
    }
    return true;
  }
}
void NSAction::RecoverHealth(CPlayer * target, int health)
{
  target->SetHP(std::min(target->GetHP()+health, target->GetMaxHP()));
}
void NSAction::DrawCardFromPlague(CPlague * plague, CPlayer * drawer)
{
  CCard * DrawedCard = plague->ChooseTopCard();
  if(DrawedCard != nullptr)
  {
    drawer->AddHolding(DrawedCard);
    plague->RemoveCardFromPlague(DrawedCard);
  }
}
void NSAction::FoldCard(CPlayer * folder, CCard * card, CPlague * DiscardPlague)
{
  DiscardPlague->InsertCardToPlague(card);
  folder->RemoveHolding(card);
}
