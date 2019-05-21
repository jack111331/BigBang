#include "Carabine.h"
#include <string>
#include "Room.h"
#include "GameEventObserver.h"
#include "Action.h"

CCarabine::CCarabine(CRoom * room, int number, Suit suit) : CEquipmentCard(room, number, suit)
{
  const std::string Name("Carabine");
  const std::string Feature("Attack range increased to 4.");
  SetName(Name);
  SetFeature(Feature);

  constexpr bool multiAttack = false;
  constexpr int attackRange = 4;
  constexpr int defendRange = 0;
  SetMultiAttack(multiAttack);
  SetAttackRange(attackRange);
  SetDefendRange(defendRange);
  GetInRoom()->GetRoomEvent()->registerOnEquip(OnEquip);
  GetInRoom()->GetRoomEvent()->registerOnUnequip(OnUnequip);
}
void CCarabine::OnEquip(CCard * card, CPlayer * Equiper)
{
  //this part of code should reuse
  if(card->GetName() == "Carabine")
  {
    NSAction::EquipItem(Equiper, card);
  }
}
void CCarabine::OnUnequip(CCard * card, CPlayer * Unequiper)
{
  //this part of code should reuse
  if(card->GetName() == "Carabine")
  {
    NSAction::UnequipItem(Unequiper, card);
  }
}
