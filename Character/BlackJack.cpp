#include "BartCassidy.h"
#include <string>
#include "../Player.h"
#include "../Action.h"


void CCharacterJack::InitCharacter()
{
  const std::string Name("Black Jack");
  const std::string Feature("Draw one more card from plague if the second drawed card flipped from plague is red.");
  const int MaxHP = 4;
  SetName(Name);
  SetFeature(Feature);
  SetID();
  SetMaxHP(MaxHP);
}
void CCharacter::DrawCard(CRoom * room, CPlayer & myself, CPlayer & target)
{
  // flip, to be continued
  //Define Normal active
  constexpr int DrawCardAmount = 2;
  for(int i = 0;i < DrawCardAmount;i++)
  {
    NSAction::DrawCardFromPlague(CPlague * plague, CPlayer * drawer);
  }
}
