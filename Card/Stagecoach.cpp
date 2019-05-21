#include "Stagecoach.h"
#include <string>
#include "Room.h"
#include "GameEventObserver.h"
#include "Action.h"
#include <vector>

CStagecoach::CStagecoach(CRoom * room, int number, Suit suit) : CCard(room, number, suit)
{
  const std::string Name("Stagecoach");
  const std::string Feature("Draw 2 card from plague.");
  SetName(Name);
  SetFeature(Feature);
}
void CStagecoach::UseCardEffect(CRoom * room, CPlayer * myself, CPlayer * target)
{
  constexpr int DrawCardAmount = 2;
  for(int i = 0;i < DrawCardAmount;i++)
  {
    NSAction::DrawCardFromPlague(room->GetPlague(), myself);
  }
  NSAction::RemoveCardToDiscardPlague(room->GetDiscardPlague(), myself, this);
}
