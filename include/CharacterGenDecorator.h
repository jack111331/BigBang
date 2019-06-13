#pragma once
#include <vector>
#include <string>
#include <map>
class CCharacterGenComponent
{
public:
  std::map<std::string, bool> & GetGenerateCharacter();
protected:
  std::map<std::string, bool> CharacterList;
};
class CCharacterGenConcreteComponent : public CCharacterGenComponent
{
public:
  CCharacterGenConcreteComponent();
};

class CCharacterGenDecorator : public CCharacterGenComponent
{
public:
  CCharacterGenDecorator(CCharacterGenComponent * Component);
  std::map<std::string, bool> & GetGenerateCharacter();
protected:
  CCharacterGenComponent * Component;
};

class CCharacterGenConcreteDecoratorGodDeveloper : public CCharacterGenDecorator
{
public:
  CCharacterGenConcreteDecoratorGodDeveloper(CCharacterGenComponent * Component);
};
