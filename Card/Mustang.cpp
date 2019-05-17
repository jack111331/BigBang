#include "Mustang.h"
#include <string>
#include "GameEventObserver.h"
#include "Action.h"

CMustang::CMustang(int number, Suit suit) : CEquipmentCard(number, suit)
{
  const std::string Name("Mustang");
  const std::string Feature("Defend range increased to 1.");
  SetName(Name);
  SetFeature(Feature);

  constexpr bool multiAttack = false;
  constexpr int attackRange = 1;
  constexpr int defendRange = 1;
  SetMultiAttack(multiAttack);
  SetAttackRange(attackRange);
  SetDefendRange(defendRange);
  CGameEventObserver::registerOnEquip(OnEquip);
  CGameEventObserver::registerOnUnequip(OnUnequip);
  //should concern unequip
}
void CMustang::OnEquip(CCard * card, CPlayer * Equiper)
{
  //this part of code should reuse
  if(card->GetName() == "Mustang")
  {
    NSAction::EquipItem(Equiper, card);
  }
}
void CMustang::OnUnequip(CCard * card, CPlayer * Unequiper)
{
  //this part of code should reuse
  if(card->GetName() == "Mustang")
  {
    NSAction::UnequipItem(Unequiper, card);
  }
}
