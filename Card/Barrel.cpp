#include "Barrel.h"
#include <string>
#include "Room.h"
#include "GameEventObserver.h"
#include "Action.h"

CBarrel::CBarrel(CRoom * room, int number, Suit suit) : CEquipmentCard(room, number, suit)
{
  const std::string Name("Barrel");
  const std::string Feature("When attacked, draw a card and determine whether it is heart. If so, then missed this attack.");
  SetName(Name);
  SetFeature(Feature);

  constexpr bool multiAttack = false;
  constexpr int attackRange = 1;
  constexpr int defendRange = 0;
  SetMultiAttack(multiAttack);
  SetAttackRange(attackRange);
  SetDefendRange(defendRange);
  GetInRoom()->GetRoomEvent()->registerOnEquip(OnEquip);
  GetInRoom()->GetRoomEvent()->registerOnUnequip(OnUnequip);
}
void CBarrel::OnEquip(CCard * card, CPlayer * Equiper)
{
  //this part of code should reuse
  if(card->GetName() == "Barrel")
  {
    NSAction::EquipItem(Equiper, card);
    card->GetInRoom()->GetRoomEvent()->registerOnPreLossBlood(OnPreLossBlood);
  }
}
bool CBarrel::OnPreLossBlood(CRoom * room, CPlayer * loser)
{
  if(loser->GetEquipment()->GetName() == "Barrel")
  {
    CCard * DrawedCard = NSAction::DrawCardFromPlagueForDetermine(room);
    if(DrawedCard->GetSuit() == Suit::Heart)
    {
      return false;
    }
  }
  return true;
}
void CBarrel::OnUnequip(CCard * card, CPlayer * Unequiper)
{
  //this part of code should reuse
  if(card->GetName() == "Barrel")
  {
    NSAction::UnequipItem(Unequiper, card);
    card->GetInRoom()->GetRoomEvent()->unregisterOnPreLossBlood(OnPreLossBlood);
  }
}
