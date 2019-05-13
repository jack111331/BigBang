#include "CharacterGenFactory.h"
#include "BartCassidy.h"
#include "BlackJack.h"
#include <string>
#include <iterator>
#include <stdlib.h>
CCharacter * NSCharacterGenFactory::createCharacter(std::string Charactername)
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
CCharacter * NSCharacterGenFactory::createCharacter(char const * Charactername)
{
  return createCharacter(std::string(Charactername));
}

CRandomCharacterPool::CRandomCharacterPool()
{
  //init character deck
  CharacterPool["Bart Cassidy"] = 0;
  CharacterPool["Black Jack"] = 0;
  //.....
  FlushChoicePool();
}
void CRandomCharacterPool::RemoveChoiceFromPool()
{
  for(std::vector<std::string>::iterator it = CharacterChoicePool.begin();it != CharacterChoicePool.end();++it)
  {
    CharacterPool.erase(*it);
  }
  CharacterChoicePool.clear();
}
void CRandomCharacterPool::FlushChoicePool()
{
  constexpr int choiceAmount = 2;
  for(int i = static_cast<int>(CharacterChoicePool.size());i < choiceAmount;i++)
  {
    std::map<std::string, bool>::iterator it = CharacterPool.begin();
    std::advance(it, rand() % CharacterPool.size());
    CharacterChoicePool.push_back(it->first);
  }
}
const std::vector<std::string> & CRandomCharacterPool::ChoiceCharacterFromPool()
{
  return CharacterChoicePool;
}
