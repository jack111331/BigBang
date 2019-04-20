#include "CharacterGenFactory.h"
#include "./Character/BartCassidy.h"
#include <string>
CCharacter * CCharacterGenFactory::createCharacter(std::string Charactername)
{
  if(Charactername == "Bart Cassidy")
  {
    return new CCharacterBart();
  }
  else
  {
    return nullptr;
  }
}
