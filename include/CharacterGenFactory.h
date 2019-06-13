#pragma once
#include "Character.h"
#include <string>
#include <map>
#include <vector>
#include "Room.h"
namespace NSCharacterGenFactory
{
  CCharacter * createCharacter(std::string Cardname, CRoom * room);
  CCharacter * createCharacter(char const * Cardname, CRoom * room);
}
class CRandomCharacterPool
{
public:
  CRandomCharacterPool(CRoom * room);
  void RemoveChoiceFromPool();
  void FlushChoicePool();
  const std::vector<std::string> & ChoiceCharacterFromPool();
private:
  std::map<std::string, bool> CharacterPool;
  std::vector<std::string> CharacterChoicePool;
};
