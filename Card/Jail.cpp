#include "Jail.h"
#include <string>
#include "Room.h"
#include "GameEventObserver.h"
#include "Action.h"

CJail::CJail(CRoom * room, int number, Suit suit) : CEquipmentCard(room, number, suit)
{
  const std::string Name("Jail");
  const std::string Feature("When equipped, draw card and determine if the drawed card is heart, then jail will be Unequiped, otherwise player will be deprived draw card right.");
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
bool CJail::UseCardEffect(CRoom * room, CPlayer * myself, CPlayer * target)
{
  if(target->GetIdentity() != Team::Sergeant)
  {
    GetInRoom()->GetRoomEvent()->callEquip(this, target);
    NSAction::RemoveCardToDiscardPlague(room->GetDiscardPlague(), myself, this);
    return true;
  }
  return false;
}
void CJail::OnEquip(CCard * card, CPlayer * Equiper)
{
  //this part of code should reuse
  if(card->GetName() == "Jail")
  {
    NSAction::EquipItem(Equiper, card);
    card->GetInRoom()->GetRoomEvent()->registerOnDrawCard(OnDrawCard);
  }
}
void CJail::OnUnequip(CCard * card, CPlayer * Unequiper)
{
  //this part of code should reuse
  if(card->GetName() == "Jail")
  {
    NSAction::UnequipItem(Unequiper, card);
    card->GetInRoom()->GetRoomEvent()->unregisterOnDrawCard(OnDrawCard);
  }
}
bool CJail::OnDrawCard(CRoom * room, CPlayer * drawer)
{
  //this part of code should reuse
  if(drawer->GetEquipment() && drawer->GetEquipment()->GetName() == "Jail")
  {
    CCard * DrawedCard = NSAction::DrawCardFromPlagueForDetermine(room);
    if(DrawedCard->GetSuit() == Suit::Heart)
    {
      room->GetDiscardPlague()->InsertCardToPlague(DrawedCard);
      drawer->ChangeEquipment(nullptr);
      return false;
    }
  }
  return true;
}
