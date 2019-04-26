#include "Action.h"
#include "Player.h"
#include "Plague.h"
#include "GameEventObserver.h"

namespace NSAction
{
  bool Attack(CPlayer * attacker, CPlayer * attackee, std::string dodgeByCard)
  {
    if(attackee->isCardInHolding(dodgeByCard))
    {
      //invoke player to choose whether he want to use this card
    }
    else
    {
      CGameEventObserver::callAttack(attater, attackee);
      attackee->SetHP(attackee->GetHP()-1);
      if(attackee->GetHP() <= 0)
      {
        CGameEventObserver::callDeath(attackee, attacker);
      }
      return true;
    }
    return false;
  }
  void RecoverHealth(CPlayer * target, int health)
  {
    target->SetHP(min(target->GetHP()+health, target->GetMaxHP()));
  }
  void DrawCardFromPlague(CPlague * plague, CPlayer * drawer)
  {
    CCard * DrawedCard = plague.RandomChooseCard();
    if(DrawedCard != nullptr)
    {
      drawer.AddHolding(DrawedCard);
      plague.RemoveCardFromPlague(DrawedCard);
    }
  }
  void ChooseCardFromPlayer(CPlayer * chooser, CPlayer * choosee)
  {

  }
  void DrawCardFromPlayer(CPlayer * drawer, CPlayer * drawee)
  {

  }
  void FoldCard(CPlayer * folder, CCard * card)
  {

  }
}
