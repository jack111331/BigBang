#pragma once
#include "Card.h"
#include <string>

namespace NSCardGenFactory
{
  CCard * createCard(std::string Cardname);
  CCard * createCard(char const * Cardname);
};
