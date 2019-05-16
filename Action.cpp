#include "Action.h"
#include "Player.h"
#include "Plague.h"
#include "GameEventObserver.h"
#include "Room.h"
#include "WrapInfo.h"

bool NSAction::Attack(CRoom * room, CPlayer * attacker, CPlayer * attackee, std::string dodgeByCard)
{
  CCard * HoldingRevoltCard = attackee->GetCardInHolding(dodgeByCard);
  if(HoldingRevoltCard != nullptr)
  {
    //invoke player to choose whether he want to use this card
    attackee->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapRevoltCard(HoldingRevoltCard));
    int Revolt;
    while((Revolt = attackee->isRevolt()) == -1)
    {
    }
    attackee->SetRevolt(-1);
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
      attackee->SetDead(true);
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
void NSAction::GiveCard(CPlayer * Giver, CPlayer * Given, int GiveCardID)
{
  Given->GetCard(GiveCardID);
  Giver->RemoveCard(GiveCardID);
}
