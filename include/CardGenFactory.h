#pragma once
#include "Card.h"
#include <string>

namespace NSCardGenFactory
{
  CCard * createCard(std::string Cardname, int Number, Suit suit);
  CCard * createCard(char const * Cardname, int Number, Suit suit);
};
