#include "DrawCardFactory.h"

IDrawCardFromPlayer * NSDrawCardFactory::DrawCard(std::string DrawCardMethod)
{
  if(DrawCardMethod == "Choose Card")
  {
    return new CChooseCard();
  }
  else if(DrawCardMethod == "Random Choose Card")
  {
    return new CRandomChooseCard();
  }
  return nullptr;
}
