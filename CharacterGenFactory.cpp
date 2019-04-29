#include "CharacterGenFactory.h"
#include "./Character/BartCassidy.h"
#include "./Character/BlackJack.h"
#include <string>
CCharacter * CCharacterGenFactory::createCharacter(std::string Charactername)
{
  if(Charactername == "Bart Cassidy")
  {
    return new CCharacterBart();
  }
  else if(Charactername == "Black Jack")
  {
    return new CCharacterJack();
  }
  else
  {
    return nullptr;
  }
}
