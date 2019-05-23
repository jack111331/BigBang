#include "Action.h"
#include "Player.h"
#include "Plague.h"
#include "GameEventObserver.h"
#include "Room.h"
#include "WrapInfo.h"
#include "EquipmentCard.h"

bool NSAction::Attack(CRoom * room, CPlayer * attacker, CPlayer * attackee, std::string dodgeByCard)
{
  CCard * HoldingRevoltCard = attackee->GetCardInHolding(dodgeByCard);
  if(HoldingRevoltCard != nullptr)
  {
    if(!room->GetRoomEvent()->callPreLossBlood(room, attackee))
    {
      return false;
    }
    //invoke player to choose whether he want to use this card
    attackee->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapRevoltCard(HoldingRevoltCard).dump());
    int Revolt;
    while((Revolt = attackee->isRevolt()) == -1)
    {
    }
    attackee->SetRevolt(-1);
    if(Revolt)
    {
      attackee->RemoveHolding(HoldingRevoltCard);
      return false;
    }
    else
    {
      room->GetRoomEvent()->callLossBlood(room, attackee, attacker);
      attackee->SetHP(attackee->GetHP()-1);
      if(attackee->GetHP() <= 0)
      {
        room->GetRoomEvent()->callDeath(room, attackee, attacker);
      }
      return true;
    }
  }
  else
  {
    room->GetRoomEvent()->callLossBlood(room, attackee, attacker);
    attackee->SetHP(attackee->GetHP()-1);
    if(attackee->GetHP() <= 0)
    {
      room->GetRoomEvent()->callDeath(room, attackee, attacker);
      attackee->SetDead(true);
    }
    return true;
  }
}
void NSAction::RecoverHealth(CPlayer * target, int health)
{
  target->SetHP(std::min(target->GetHP()+health, target->GetMaxHP()));
}
void NSAction::AutoFlushPlague(CRoom * room)
{
  CPlague * Plague = room->GetPlague();
  CPlague * DiscardPlague = room->GetDiscardPlague();
  if(Plague->GetPlagueCardAmount())
  {
    for(int i = 0;i < DiscardPlague->GetPlagueCardAmount();i++)
    {
      CCard * TopCard = DiscardPlague->ChooseTopCard();
      Plague->InsertCardToPlague(TopCard);
      DiscardPlague->RemoveCardFromPlague(TopCard);
    }
  }
}
void NSAction::DrawCardFromPlague(CRoom * room, CPlayer * drawer)
{
  AutoFlushPlague(room);
  CPlague * Plague = room->GetPlague();
  CCard * DrawedCard = Plague->ChooseTopCard();
  if(DrawedCard != nullptr)
  {
    drawer->AddHolding(DrawedCard);
    Plague->RemoveCardFromPlague(DrawedCard);
  }
}
void NSAction::RemoveCardToDiscardPlague(CPlague * discardPlague, CPlayer * remover, CCard * card)
{
  remover->RemoveHolding(card);
  discardPlague->InsertCardToPlague(card);
}
void NSAction::FoldCard(CPlayer * folder, CCard * card, CPlague * DiscardPlague)
{
  DiscardPlague->InsertCardToPlague(card);
  folder->RemoveHolding(card);
}
void NSAction::GiveCard(CPlayer * Giver, CPlayer * Given, int GiveCardID)
{
  Given->GetCard(GiveCardID);
  Giver->RemoveCard(GiveCardID);
}
void NSAction::EquipItem(CPlayer * equiper, CCard * equipmentCard)
{
  CEquipmentCard * EquipCard = static_cast<CEquipmentCard *>(equipmentCard);
  EquipCard->ChangeOwner(equiper);
  equiper->ChangeEquipment(EquipCard);
  equiper->SetAttackRange(EquipCard->GetAttackRange());
  equiper->SetMinusRange(EquipCard->GetDefendRange());
  equiper->SetMultiAttack(EquipCard->isMultiAttack());
}
void NSAction::UnequipItem(CPlayer * equiper, CCard * equipmentCard)
{
  CEquipmentCard * EquipCard = static_cast<CEquipmentCard *>(equipmentCard);
  EquipCard->ChangeOwner(nullptr);
  equiper->ChangeEquipment(nullptr);
  equiper->SetAttackRange(equiper->GetCharacter()->GetDefaultAttackRange());
  equiper->SetAddRange(equiper->GetCharacter()->GetDefaultAddRange());
  equiper->SetMinusRange(equiper->GetCharacter()->GetDefaultMinusRange());
  equiper->SetMinusRange(equiper->GetCharacter()->GetDefaultMultiAttack());
}
CCard * NSAction::DrawCardFromPlagueForDetermine(CRoom * room)
{
  AutoFlushPlague(room);
  CPlague * Plague = room->GetPlague();
  CCard * DrawedCard = Plague->ChooseTopCard();
  if(DrawedCard != nullptr)
  {
    Plague->RemoveCardFromPlague(DrawedCard);
  }
  return DrawedCard;
}
