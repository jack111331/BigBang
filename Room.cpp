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
  player->SetUser(user);
  user->SetPlayer(player);
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
void CRoom::GameLoop(CRoom * room)
{
  //let player choose card
  //generate 2 random character, this two can't be identical
  for(std::vector<CPlayer *>::iterator it = room->GetPlayerList().begin();it != room->GetPlayerList().end();++it)
  {
//    it->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapChooseCharacter(std::string CharacterName_1, std::string CharacterName_2));

  }
}
CRoom::~CRoom()
{
  for(std::vector<CPlayer *>::iterator it = playerList.begin();it != playerList.end();++it)
  {
    delete *it;
  }
  playerList.clear();
}
