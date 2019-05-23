#include "Dynamite.h"
#include <string>
#include "Room.h"
#include "GameEventObserver.h"
#include "Action.h"

CDynamite::CDynamite(CRoom * room, int number, Suit suit) : CEquipmentCard(room, number, suit)
{
  const std::string Name("Dynamite");
  const std::string Feature("When equipped, draw card and determine if the drawed card is spade and its number is between 2~9, then dynamite will exploded and the player will loss 3 HP, otherwise this dynamite will send to player next to him.");
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
void CDynamite::OnEquip(CCard * card, CPlayer * Equiper)
{
  //this part of code should reuse
  if(card->GetName() == "Dynamite")
  {
    card->GetInRoom()->GetRoomEvent()->registerOnDrawCard(OnDrawCard);
  }
}
void CDynamite::OnUnequip(CCard * card, CPlayer * Unequiper)
{
  //this part of code should reuse
  if(card->GetName() == "Dynamite")
  {
    card->GetInRoom()->GetRoomEvent()->unregisterOnDrawCard(OnDrawCard);
  }
}
bool CDynamite::OnDrawCard(CRoom * room, CPlayer * drawer)
{
  //this part of code should reuse
  if(drawer->GetEquipment()->GetName() == "Dynamite")
  {
    CCard * DrawedCard = NSAction::DrawCardFromPlagueForDetermine(room);
    if(DrawedCard->GetSuit() == Suit::Spade && DrawedCard->GetNumber() >= 2 && DrawedCard->GetNumber() <= 9)
    {
      drawer->SetHP(drawer->GetHP() - 3);
      if(drawer->GetHP() <= 0)
      {
        room->GetRoomEvent()->callDeath(room, drawer, drawer);
        drawer->SetDead(true);
      }
      drawer->ChangeEquipment(nullptr);
    }
    else
    {
      CPlayer * NextPlayer = room->GetNextPlayer(drawer);
      NSAction::GiveCard(drawer, NextPlayer, drawer->GetEquipment()->GetID());
      NextPlayer->UseCard(room, "Dynamite", nullptr);//equip immediately
    }
  }
  return true;
}
