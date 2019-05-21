#include "Schofield.h"
#include <string>
#include "Room.h"
#include "GameEventObserver.h"
#include "Action.h"

CSchofield::CSchofield(CRoom * room, int number, Suit suit) : CEquipmentCard(room, number, suit)
{
  const std::string Name("Schofield");
  const std::string Feature("Attack range increased to 2.");
  SetName(Name);
  SetFeature(Feature);

  constexpr bool multiAttack = false;
  constexpr int attackRange = 2;
  constexpr int defendRange = 0;
  SetMultiAttack(multiAttack);
  SetAttackRange(attackRange);
  SetDefendRange(defendRange);
  GetInRoom()->GetRoomEvent()->registerOnEquip(OnEquip);
  GetInRoom()->GetRoomEvent()->registerOnUnequip(OnUnequip);
}
void CSchofield::OnEquip(CCard * card, CPlayer * Equiper)
{
  //this part of code should reuse
  if(card->GetName() == "Schofield")
  {
    NSAction::EquipItem(Equiper, card);
  }
}
void CSchofield::OnUnequip(CCard * card, CPlayer * Unequiper)
{
  //this part of code should reuse
  if(card->GetName() == "Schofield")
  {
    NSAction::UnequipItem(Unequiper, card);
  }
}
