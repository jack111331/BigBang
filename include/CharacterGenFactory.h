#pragma once
#include "Character.h"
#include <string>
#include <map>
#include <vector>

namespace NSCharacterGenFactory
{
  CCharacter * createCharacter(std::string Cardname);
  CCharacter * createCharacter(char const * Cardname);
}
class CRandomCharacterPool
{
public:
  CRandomCharacterPool();
  void RemoveChoiceFromPool();
  void FlushChoicePool();
  const std::vector<std::string> & ChoiceCharacterFromPool();
private:
  std::map<std::string, bool> CharacterPool;
  std::vector<std::string> CharacterChoicePool;
};
