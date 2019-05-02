#include "CardGenFactory.h"
#include "./Card/Winchester.h"
#include <string>

CCard * NSCardGenFactory::createCard(std::string Cardname)
{
  if(Cardname == "Winchester")
  {
    return new CWinchester();
  }
  else
  {
    return nullptr;
  }
}
CCard * NSCardGenFactory::createCard(char const * Cardname)
{
  return createCard(std::string(Cardname));
}
