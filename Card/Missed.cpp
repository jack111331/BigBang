#include "Missed.h"
#include <string>
#include "Room.h"
#include "Action.h"

CMissed::CMissed(CRoom * room, int number, Suit suit) : CCard(room, number, suit)
{
  const std::string Name("Missed!");
  const std::string Feature("When not on your round, dodge one bang! attack.");
  SetName(Name);
  SetFeature(Feature);
}
