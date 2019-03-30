#pragma once

#include <string>
class CCharacter
{
public:
  const std::string & GetName() const;
  const std::string & GetFeature() const;
  int GetID() const;
  int GetMaxHP() const;

  void SetName(const std::string & name);
  void SetFeature(const std::string & feature);
  void SetID(int id);
  void SetMaxHP(int maxHP);
private:
  std::string Name;
  std::string Feature;
  int ID;
  int MaxHP;
};
