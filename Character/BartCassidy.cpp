#include "BartCassidy.h"
#include <string>
#include "../Player.h"
#include "../GameEventObserver.h"
#include "../Action.h"
#include "../Room.h"


CCharacterBart::CCharacterBart()
{
  const std::string Name("Bart Cassidy");
  const std::string Feature("Draw one card from plague while HP decrease one point.");
  const int MaxHP = 4;
  SetName(Name);
  SetFeature(Feature);
  SetID();
  SetMaxHP(MaxHP);
  CGameEventObserver::registerOnLossBlood(OnLossBlood);
}
void CCharacterBart::OnLossBlood(CRoom * room, CPlayer * loser)
{
  //it need room to get plague
  if(loser->GetCharacter()->GetName() == "Bart Cassidy")
  {
    NSAction::DrawCardFromPlague(room->GetPlague(), loser);
  }
}
CCharacterBart::~CCharacterBart()
{
  CGameEventObserver::unregisterOnLossBlood(OnLossBlood);
}
