#include "BlackJack.h"
#include <string>
#include "Player.h"
#include "Action.h"
#include "Room.h"


CCharacterJack::CCharacterJack(CRoom * room) : CCharacter(room)
{
  const std::string Name("Black Jack");
  const std::string Feature("Draw one more card from plague if the second drawed card flipped from plague is red.");
  const int MaxHP = 4;
  const int AttackRange = 1;
  const int AddRange = 0;
  const int MinusRange = 0;
  const bool HasMultiAttack = false;
  SetName(Name);
  SetFeature(Feature);
  SetID();
  SetMaxHP(MaxHP);
  SetAttackRange(AttackRange);
  SetAddRange(AddRange);
  SetMinusRange(MinusRange);
  SetMultiAttack(HasMultiAttack);
}
void CCharacterJack::DrawCard(CRoom * room, CPlayer * myself)
{
  // flip, to be continued
  //Define Normal active
  NSAction::DrawCardFromPlague(room, myself);
  CCard * DrawedCard = NSAction::DrawCardFromPlagueForDetermine(room);
  if(DrawedCard->GetSuit() == Suit::Heart || DrawedCard->GetSuit() == Suit::Diamond)
  {
    NSAction::DrawCardFromPlague(room, myself);
  }
  myself->AddHolding(DrawedCard);
}
