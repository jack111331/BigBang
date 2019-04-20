#pragma once
#include "Character.h"
#include <string>

class CCharacterGenFactory
{
public:
  static CCharacter * createCharacter(std::string Cardname);
};
