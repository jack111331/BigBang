#include "Winchester.h"
#include <string>
#include "Room.h"
#include "GameEventObserver.h"
#include "Action.h"

CWinchester::CWinchester(int number, Suit suit) : CEquipmentCard(number, suit)
{
  const std::string Name("Winchester");
  const std::string Feature("Attack range increased to 5.");
  SetName(Name);
  SetFeature(Feature);

  constexpr bool multiAttack = false;
  constexpr int attackRange = 5;
  constexpr int defendRange = 5;
  SetMultiAttack(multiAttack);
  SetAttackRange(attackRange);
  SetDefendRange(defendRange);
  CGameEventObserver::registerOnEquip(OnEquip);
  CGameEventObserver::registerOnUnequip(OnUnequip);
  //should concern unequip
}
void CWinchester::OnEquip(CCard * card, CPlayer * Equiper)
{
  //this part of code should reuse
  if(card->GetName() == "Winchester")
  {
    NSAction::UnequipItem(Equiper, card);
  }
}
void CWinchester::OnUnequip(CCard * card, CPlayer * Unequiper)
{
  //this part of code should reuse
  if(card->GetName() == "Winchester")
  {
    NSAction::UnequipItem(Unequiper, card);
  }
}
