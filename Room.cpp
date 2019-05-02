#include "Room.h"
#include "User.h"
CRoom::CRoom()
{
  this->plague = new CPlague;
  this->plague->InitPlague();
  this->discardPlague = new CPlague;
}
void CRoom::PlayerJoin(CUser * user)
{
  CPlayer * player = new CPlayer;
  //to be edit
  player->SetName(user->GetName());
  //let player choose card
  playerList.push_back(player);
}
CPlague * CRoom::GetPlague()
{
  return this->plague;
}
CPlague * CRoom::GetDiscardPlague()
{
  return this->discardPlague;
}
std::vector<CPlayer *> & CRoom::GetPlayerList()
{
  return this->playerList;
}
CRoom::~CRoom()
{
  for(std::vector<CPlayer *>::iterator it = playerList.begin();it != playerList.end();++it)
  {
    delete *it;
  }
  playerList.clear();
}
