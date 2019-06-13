#include "CharacterGenFactory.h"
#include "BartCassidy.h"
#include "BlackJack.h"
#include "SuzyLafayette.h"
#include "ElGringo.h"
#include "VultureSam.h"
#include "PaulRegret.h"
#include "RoseDoolan.h"
#include "WillyTheKid.h"
#include "GodDeveloper.h"
#include "CharacterGenDecorator.h"
#include <string>
#include <iterator>
#include <stdlib.h>
#include "Lounge.h"
#include "ExclusiveCardStore.h"
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
  else if(Charactername == "God Developer")
  {
    return new CCharacterGod(room);
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

CRandomCharacterPool::CRandomCharacterPool(CRoom * room)
{
  //init character deck
  CCharacterGenComponent * CharacterComponent = new CCharacterGenConcreteComponent();
  if(room->GetLounge()->getEnableExclusiveCard())
  {
    std::map<uint32_t, bool> CharacterCardSet;
    for(std::vector<CPlayer *>::iterator it = room->GetPlayerList().begin();it != room->GetPlayerList().end();++it)
    {
      std::vector<uint32_t> CardList = (*it)->GetUser()->GetExclusiveCardInventory()->GetCharacterCardList();
      for(int i = 0;i < static_cast<int>(CardList.size());++i)
      {
        CharacterCardSet[CardList[i]] = 1;
      }
    }
    CharacterComponent = CExclusiveCardStore::GetInstance()->GenerateExclusiveCharacter(CharacterCardSet, CharacterComponent);
  }
  CharacterPool = CharacterComponent->GetGenerateCharacter();
  //.....
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
  srand(time(NULL));
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
