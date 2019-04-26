#include "BartCassidy.h"
#include <string>
#include "../Player.h"
#include "../GameEventObserver.h"
#include "../Action.h"


void CCharacterBart::InitCharacter()
{
  const std::string Name("Bart Cassidy");
  const std::string Feature("Draw one card from plague while HP decrease one point.");
  const int MaxHP = 4;
  SetName(Name);
  SetFeature(Feature);
  SetID();
  SetMaxHP(MaxHP);
  CGameEventObserver::registerOnAttack(OnAttacked);
}
void CCharacterBart::OnAttacked(CPlayer * attacker, CPlayer * attackee)
{
  //if attackee is me, how to implement..???
  if()
  {
    NSAction::DrawCardFromPlague(CPlague * plague, attackee);
  }
}
