#include "CardGenFactory.h"
#include "./Card/Winchester.h"
#include <string>
namespace NSCardGenFactory
{
  CCard * createCard(std::string Cardname)
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
  CCard * createCard(char const * Cardname)
  {
    return createCard(std::string(Cardname));
  }
};
