#include "Winchester.h"
#include <string>
#include "Room.h"
#include "GameEventObserver.h"

CWinchester::CWinchester()
{
  const std::string Name("Winchester");
  const std::string Feature("Attack range increased to 5.");
  constexpr int Number = 8;
  constexpr Suit suit = Suit::Spade;
  SetName(Name);
  SetFeature(Feature);
  SetNumber(Number);
  SetSuit(suit);

  constexpr bool multiAttack = 0;
  constexpr int attackRange = 5;
  SetMultiAttack(multiAttack);
  SetAttackRange(attackRange);
  CGameEventObserver::registerOnEquip(OnEquip);
  //should concern unequip
}
void CWinchester::OnEquip(CCard * card, CPlayer * Equiper)
{
  //this part of code should reuse
  if(card->GetName() == "Winchester")
  {
    card->ChangeOwner(Equiper);
    Equiper->ChangeWeapon(card);
    Equiper->SetAttackRange(5);
  }
}
