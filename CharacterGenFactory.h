#pragma once
#include "Character.h"
#include <string>

namespace NSCharacterGenFactory
{
  CCharacter * createCharacter(std::string Cardname);
  CCharacter * createCharacter(char const * Cardname);
}
