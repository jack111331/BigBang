#include "Volcanic.h"
#include <string>
#include "Room.h"
#include "GameEventObserver.h"
#include "Action.h"

CVolcanic::CVolcanic(int number, Suit suit) : CEquipmentCard(number, suit)
{
  const std::string Name("Volcanic");
  const std::string Feature("Attack range is 1, player can multi attack other.");
  SetName(Name);
  SetFeature(Feature);

  constexpr bool multiAttack = true;
  constexpr int attackRange = 1;
  constexpr int defendRange = 0;
  SetMultiAttack(multiAttack);
  SetAttackRange(attackRange);
  SetDefendRange(defendRange);
  CGameEventObserver::registerOnEquip(OnEquip);
  CGameEventObserver::registerOnUnequip(OnUnequip);
  //should concern unequip
}
void CVolcanic::OnEquip(CCard * card, CPlayer * Equiper)
{
  //this part of code should reuse
  if(card->GetName() == "Volcanic")
  {
    NSAction::UnequipItem(Equiper, card);
  }
}
void CVolcanic::OnUnequip(CCard * card, CPlayer * Unequiper)
{
  //this part of code should reuse
  if(card->GetName() == "Volcanic")
  {
    NSAction::UnequipItem(Unequiper, card);
  }
}
