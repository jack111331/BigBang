#include "Room.h"
#include "User.h"
#include "CharacterGenFactory.h"
#include "WrapInfo.h"
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
void CRoom::LoopToCheckHaveCharacter()
{
  int PlayerHaveCharacter;
  while(1)
  {
    PlayerHaveCharacter = 0;
    for(std::vector<CPlayer *>::iterator it = GetPlayerList().begin();it != GetPlayerList().end();++it)
    {
      if((*it)->GetCharacter())
      {
        PlayerHaveCharacter++;
      }
    }
    if(PlayerHaveCharacter == static_cast<int>(GetPlayerList().size()))
    {
      break;
    }
  }
}
bool CRoom::isGameEnd()
{
}
void CRoom::GameLoop(CRoom * room)
{
  //let player choose card
  //generate 2 random character, this two can't be identical
  CRandomCharacterPool * CharacterPool = new CRandomCharacterPool;
  for(std::vector<CPlayer *>::iterator it = room->GetPlayerList().begin();it != room->GetPlayerList().end();++it)
  {
    std::vector<std::string> CharacterChoicePool = CharacterPool->ChoiceCharacterFromPool();
    //hard code to have 2 character
    (*it)->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapChooseCharacter(CharacterChoicePool[0], CharacterChoicePool[1]));
    CharacterPool->RemoveChoiceFromPool();
  }
  //loop to check if everybody has character card
  room->LoopToCheckHaveCharacter();
  //auto choose team for player, tbc
  while(!room->isGameEnd())
  {
    for(std::vector<CPlayer *>::iterator it = room->GetPlayerList().begin();it != room->GetPlayerList().end();++it)
    {
      //update player's info
      (*it)->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapPublicGameInfo(room, *it));
    }

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
