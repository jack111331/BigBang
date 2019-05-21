#include "Remington.h"
#include <string>
#include "Room.h"
#include "GameEventObserver.h"
#include "Action.h"

CRemington::CRemington(CRoom * room, int number, Suit suit) : CEquipmentCard(room, number, suit)
{
  const std::string Name("Remington");
  const std::string Feature("Attack range increased to 3.");
  SetName(Name);
  SetFeature(Feature);

  constexpr bool multiAttack = false;
  constexpr int attackRange = 3;
  constexpr int defendRange = 0;
  SetMultiAttack(multiAttack);
  SetAttackRange(attackRange);
  SetDefendRange(defendRange);
  GetInRoom()->GetRoomEvent()->registerOnEquip(OnEquip);
  GetInRoom()->GetRoomEvent()->registerOnUnequip(OnUnequip);
}
void CRemington::OnEquip(CCard * card, CPlayer * Equiper)
{
  //this part of code should reuse
  if(card->GetName() == "Remington")
  {
    NSAction::EquipItem(Equiper, card);
  }
}
void CRemington::OnUnequip(CCard * card, CPlayer * Unequiper)
{
  //this part of code should reuse
  if(card->GetName() == "Remington")
  {
    NSAction::UnequipItem(Unequiper, card);
  }
}
