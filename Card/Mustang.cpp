#include "Mustang.h"
#include <string>
#include "GameEventObserver.h"
#include "Action.h"
#include "Room.h"

CMustang::CMustang(CRoom * room, int number, Suit suit) : CEquipmentCard(room, number, suit)
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
  GetInRoom()->GetRoomEvent()->registerOnEquip(OnEquip);
  GetInRoom()->GetRoomEvent()->registerOnUnequip(OnUnequip);
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
