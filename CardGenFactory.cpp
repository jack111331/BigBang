#include "CardGenFactory.h"
#include "Winchester.h"
#include <string>

CCard * NSCardGenFactory::createCard(std::string Cardname, CRoom * room, int Number, Suit suit)
{
  if(Cardname == "Winchester")
  {
    return new CWinchester(room, Number, suit);
  }
  else
  {
    return nullptr;
  }
}
CCard * NSCardGenFactory::createCard(char const * Cardname, CRoom * room, int Number, Suit suit)
{
  return createCard(std::string(Cardname), room, Number, suit);
}
