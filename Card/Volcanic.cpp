#include "Volcanic.h"
#include <string>
#include "Room.h"
#include "GameEventObserver.h"
#include "Action.h"

CVolcanic::CVolcanic(CRoom * room, int number, Suit suit) : CEquipmentCard(room, number, suit)
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
  GetInRoom()->GetRoomEvent()->registerOnEquip(OnEquip);
  GetInRoom()->GetRoomEvent()->registerOnUnequip(OnUnequip);
}
void CVolcanic::OnEquip(CCard * card, CPlayer * Equiper)
{
  //this part of code should reuse
  if(card->GetName() == "Volcanic")
  {
    NSAction::EquipItem(Equiper, card);
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
