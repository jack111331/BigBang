#include "Wellsfargo.h"
#include <string>
#include "Room.h"
#include "GameEventObserver.h"
#include "Action.h"
#include <vector>

CWellsfargo::CWellsfargo(CRoom * room, int number, Suit suit) : CCard(room, number, suit)
{
  const std::string Name("Wells fargo");
  const std::string Feature("Draw 3 card from plague.");
  SetName(Name);
  SetFeature(Feature);
}
bool CWellsfargo::UseCardEffect(CRoom * room, CPlayer * myself, CPlayer * target)
{
  constexpr int DrawCardAmount = 3;
  for(int i = 0;i < DrawCardAmount;i++)
  {
    NSAction::DrawCardFromPlague(room, myself);
  }
  NSAction::RemoveCardToDiscardPlague(room->GetDiscardPlague(), myself, this);
  return true;
}
