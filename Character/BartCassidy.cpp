#include "BartCassidy.h"
#include <string>
#include "../Player.h"


void CCharacterBart::InitCharacter()
{
  const std::string Name("Bart Cassidy");
  const std::string Feature("Draw one card from plague while HP decrease one point.");
  const int MaxHP = 4;
  SetName(Name);
  SetFeature(Feature);
  SetID();
  SetMaxHP(MaxHP);
}
void CCharacterBart::BeAttacked(CPlague & plague, CPlayer & myself, CPlayer & target, std::vector<CPlayer *> & allPlayer)
{
  if(myself.isCardInHolding(CCard::GetTypeID(std::string("Miss!"))))
  {
  }
  else
  {
    myself.SetHP(myself.GetHP()-1);
    myself.DrawCard(plague, target, allPlayer);
  }
}
