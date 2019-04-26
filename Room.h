#pragma once
#include "Plague.h"
#include "Player.h"
#include <vector>
class CRoom
{
public:
  CRoom();
  void PlayerJoin(CPlayer * player);
  CPlague & GetPlague();
  std::vector<CPlayer *> & GetPlayerList();
  ~CRoom();
private:
  CPlague plague;
  std::vector<CPlayer *> playerList;
};
