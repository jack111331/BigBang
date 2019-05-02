#pragma once
#include "Plague.h"
#include "Player.h"
#include <vector>
class CUser;
class CRoom
{
public:
  CRoom();
  void PlayerJoin(CUser * user);
  CPlague * GetPlague();
  CPlague * GetDiscardPlague();
  std::vector<CPlayer *> & GetPlayerList();
  //win lose judge
  ~CRoom();
private:
  CPlague * plague;
  CPlague * discardPlague;
  std::vector<CPlayer *> playerList;
};
