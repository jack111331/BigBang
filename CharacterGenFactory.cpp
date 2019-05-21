#include "CharacterGenFactory.h"
#include "BartCassidy.h"
#include "BlackJack.h"
#include "SuzyLafayette.h"
#include "ElGringo.h"
#include "VultureSam.h"
#include "PaulRegret.h"
#include "RoseDoolan.h"
#include "WillyTheKid.h"
#include <string>
#include <iterator>
#include <stdlib.h>
CCharacter * NSCharacterGenFactory::createCharacter(std::string Charactername, CRoom * room)
{
  if(Charactername == "Bart Cassidy")
  {
    return new CCharacterBart(room);
  }
  else if(Charactername == "Black Jack")
  {
    return new CCharacterJack(room);
  }
  else if(Charactername == "Suzy Lafayette")
  {
    return new CCharacterLafayette(room);
  }
  else if(Charactername == "El Gringo")
  {
    return new CCharacterGringo(room);
  }
  else if(Charactername == "Vulture Sam")
  {
    return new CCharacterSam(room);
  }
  else if(Charactername == "Paul Regret")
  {
    return new CCharacterPaul(room);
  }
  else if(Charactername == "Rose Doolan")
  {
    return new CCharacterRose(room);
  }
  else if(Charactername == "Willy The Kid")
  {
    return new CCharacterWilly(room);
  }
  else
  {
    return nullptr;
  }
}
CCharacter * NSCharacterGenFactory::createCharacter(char const * Charactername, CRoom * room)
{
  return createCharacter(std::string(Charactername), room);
}

CRandomCharacterPool::CRandomCharacterPool()
{
  //init character deck
  CharacterPool["Bart Cassidy"] = 0;
  CharacterPool["Black Jack"] = 0;
  CharacterPool["Suzy Lafayette"] = 0;
  CharacterPool["El Gringo"] = 0;
  CharacterPool["Vulture Sam"] = 0;
  CharacterPool["Paul Regret"] = 0;
  CharacterPool["Rose Doolan"] = 0;
  CharacterPool["Willy The Kid"] = 0;
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
    CharacterPool.erase(it);
  }
}
const std::vector<std::string> & CRandomCharacterPool::ChoiceCharacterFromPool()
{
  return CharacterChoicePool;
}
