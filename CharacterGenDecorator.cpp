#include "CharacterGenDecorator.h"
#include "CharacterGenFactory.h"
#include "Room.h"
std::map<std::string, bool> & CCharacterGenComponent::GetGenerateCharacter()
{
  return CharacterList;
}
CCharacterGenConcreteComponent::CCharacterGenConcreteComponent()
{
  CharacterList["Bart Cassidy"] = 0;
  CharacterList["Black Jack"] = 0;
  CharacterList["Suzy Lafayette"] = 0;
  CharacterList["El Gringo"] = 0;
  CharacterList["Vulture Sam"] = 0;
  CharacterList["Paul Regret"] = 0;
  CharacterList["Rose Doolan"] = 0;
  CharacterList["Willy The Kid"] = 0;
}
CCharacterGenDecorator::CCharacterGenDecorator(CCharacterGenComponent * Component)
{
  this->Component = Component;
}
CCharacterGenConcreteDecoratorGodDeveloper::CCharacterGenConcreteDecoratorGodDeveloper(CCharacterGenComponent * Component) : CCharacterGenDecorator(Component)
{
  this->Component->GetGenerateCharacter()["God Developer"] = 0;
}
std::map<std::string, bool> & CCharacterGenDecorator::GetGenerateCharacter()
{
  return this->Component->GetGenerateCharacter();
}
