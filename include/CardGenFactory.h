#pragma once
#include "Card.h"
#include <string>

namespace NSCardGenFactory
{
  CCard * createCard(std::string Cardname, CRoom * room, int Number, Suit suit);
  CCard * createCard(char const * Cardname, CRoom * room, int Number, Suit suit);
};
