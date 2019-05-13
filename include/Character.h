#pragma once

#include <string>
#include <vector>

class CPlayer;
class CPlague;

class CRoom;

class CCharacter
{
public:
  CCharacter();
  ~CCharacter();
  void DrawCard(CRoom * room, CPlayer * myself);
  void Attack(CRoom * room, CPlayer * myself, CPlayer * target);

  const std::string & GetName() const;
  const std::string & GetFeature() const;
  int GetID() const;
  int GetMaxHP() const;

  void SetName(const std::string & name);
  void SetFeature(const std::string & feature);
  void SetID();
  void SetMaxHP(int maxHP);
protected:
  static int CurrentID;
private:
  std::string Name;
  std::string Feature;
  int ID;
  int MaxHP;
};
