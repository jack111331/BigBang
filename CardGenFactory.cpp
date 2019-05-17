#include "CardGenFactory.h"
#include "Winchester.h"
#include <string>

CCard * NSCardGenFactory::createCard(std::string Cardname, int Number, Suit suit)
{
  if(Cardname == "Winchester")
  {
    return new CWinchester(Number, suit);
  }
  else
  {
    return nullptr;
  }
}
CCard * NSCardGenFactory::createCard(char const * Cardname, int Number, Suit suit)
{
  return createCard(std::string(Cardname), Number, suit);
}
