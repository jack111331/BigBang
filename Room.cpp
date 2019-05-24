#include "Room.h"
#include "User.h"
#include "CharacterGenFactory.h"
#include "WrapInfo.h"
#include "Action.h"
CRoom::CRoom()
{
  this->plague = new CPlague;
  this->RoomEvent = new CGameEventObserver;
  this->plague->InitPlague(this);
  this->discardPlague = new CPlague;
}
void CRoom::PlayerJoin(CUser * user)
{
  CPlayer * player = new CPlayer;
  player->SetUser(user);
  user->SetPlayer(player);
  player->SetPosition(static_cast<int>(playerList.size()));
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
    for(std::vector<CPlayer *>::iterator it = playerList.begin();it != playerList.end();++it)
    {
      if((*it)->GetCharacter())
      {
        PlayerHaveCharacter++;
      }
    }
    if(PlayerHaveCharacter == static_cast<int>(playerList.size()))
    {
      break;
    }
  }
}
WinCondition CRoom::isGameEnd()
{
  int TeamSurviveAmount[4] = {};
  for(std::vector<CPlayer *>::iterator it = GetPlayerList().begin();it != GetPlayerList().end();++it)
  {
    if(!(*it)->isDead())
    {
      TeamSurviveAmount[static_cast<int>((*it)->GetIdentity())]++;
    }
  }
  if(!TeamSurviveAmount[static_cast<int>(Team::Sergeant)] && !TeamSurviveAmount[static_cast<int>(Team::ChiefSergeant)] && !TeamSurviveAmount[static_cast<int>(Team::BadAss)])
  {
    return WinCondition::TraitorWin;
  }
  else if(!TeamSurviveAmount[static_cast<int>(Team::Sergeant)])
  {
    return WinCondition::SergeantWin;
  }
  else if(!TeamSurviveAmount[static_cast<int>(Team::BadAss)] && !TeamSurviveAmount[static_cast<int>(Team::Traitor)])
  {
    return WinCondition::BadAssWin;
  }
  return WinCondition::None;
}
void CRoom::AutoChooseTeam()
{
  Team teamDistribute[7] =
  {
    Team::Sergeant,
    Team::BadAss,
    Team::BadAss,
    Team::Traitor,
    Team::ChiefSergeant,
    Team::BadAss,
    Team::ChiefSergeant
  };
  std::random_shuffle(teamDistribute, teamDistribute + static_cast<int>(playerList.size()));
  int currentTeam = 0;
  for(std::vector<CPlayer *>::iterator it = playerList.begin();it != playerList.end();++it)
  {
    (*it)->SetIdentity(teamDistribute[currentTeam++]);
  }
}
CPlayer * CRoom::GetNextPlayer(CPlayer * CurrentPlayer)
{
  int found = false;
  for(std::vector<CPlayer *>::iterator it = playerList.begin();;++it)
  {
    if(it == playerList.end())
    {
      it = playerList.begin();
    }
    if(found && !((*it)->isDead()))
    {
      return *it;
    }
    if(*it == CurrentPlayer)
    {
      found = true;
    }
  }
  return nullptr;
}
CPlayer * CRoom::GetPlayerByPosition(int Position)
{
  for(std::vector<CPlayer *>::iterator it = playerList.begin();;++it)
  {
    if((*it)->GetPosition() == Position)
    {
      return *it;
    }
  }
  return nullptr;
}
CGameEventObserver * CRoom::GetRoomEvent() const
{
  return this->RoomEvent;
}
void CRoom::UpdatePlayerPublicInfo()
{
  for(std::vector<CPlayer *>::iterator it = playerList.begin();it != playerList.end();++it)
  {
    //update player's info
    //bug
    (*it)->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapPublicGameInfo(this, *it).dump());
  }
}
void CRoom::InitPlayerState()
{
  for(std::vector<CPlayer *>::iterator it = playerList.begin();it != playerList.end();++it)
  {
    //setup max hp
    (*it)->SetMaxHP((*it)->GetCharacter()->GetMaxHP());
    if((*it)->GetIdentity() == Team::Sergeant)
    {
      (*it)->SetMaxHP((*it)->GetMaxHP() + 1);
    }
    //setup initial hp
    (*it)->SetHP((*it)->GetMaxHP());
    //give player corresponding card
    for(int i = 1;i <= (*it)->GetMaxHP();i++)
    {
      NSAction::DrawCardFromPlague(this, *it);
    }
  }
}
int CRoom::GetDistance(CPlayer * Watcher, CPlayer * Watchee)
{
  int minDistance = 666666;
  for(std::vector<CPlayer *>::iterator it = playerList.begin();it != playerList.end();++it)
  {
    if((*it) == Watcher)
    {
      int distance = 1;
      for(std::vector<CPlayer *>::iterator it_begin = ++it;;)
      {
        if((*it_begin) == Watchee)
        {
          minDistance = std::min(minDistance, distance);
          distance = 0;
        }
        else if((*it_begin) == Watcher)
        {
          minDistance = std::min(minDistance, distance);
          break;
        }
        if(!(*it_begin)->isDead())
        {
          distance++;
        }
        it_begin++;
      }
      break;
    }
  }
  return std::max(0, minDistance + Watcher->GetAddRange() - Watchee->GetMinusRange());
}
int CRoom::GetAlivePlayer()
{
  int AliveAmount = 0;
  for(std::vector<CPlayer *>::iterator it = playerList.begin();it != playerList.end();++it)
  {
    if(!(*it)->isDead())
    {
      AliveAmount++;
    }
  }
  return AliveAmount;
}
void CRoom::InitPlayerRoundState(CPlayer * player)
{
  player->SetAttacked(false);
  player->SetEndUsingCard(false);
}
void CRoom::EndGame(WinCondition GameEndState)
{
  for(std::vector<CPlayer *>::iterator it = playerList.begin();it != playerList.end();++it)
  {
    if(((*it)->GetIdentity() == Team::Sergeant || (*it)->GetIdentity() == Team::ChiefSergeant) && GameEndState == WinCondition::SergeantWin)
    {
      (*it)->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapEndGame(1).dump());
      (*it)->GetUser()->SetWin((*it)->GetUser()->GetWin() + 1);
    }
    else if((*it)->GetIdentity() == Team::BadAss && GameEndState == WinCondition::BadAssWin)
    {
      (*it)->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapEndGame(1).dump());
      (*it)->GetUser()->SetWin((*it)->GetUser()->GetWin() + 1);
    }
    else if((*it)->GetIdentity() == Team::Traitor && GameEndState == WinCondition::TraitorWin)
    {
      (*it)->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapEndGame(1).dump());
      (*it)->GetUser()->SetWin((*it)->GetUser()->GetWin() + 1);
    }
    else
    {
      (*it)->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapEndGame(0).dump());
      (*it)->GetUser()->SetLose((*it)->GetUser()->GetLose() + 1);
    }
  }
  // post process some thing..
}

void CRoom::GameLoop(CRoom * room)
{
  //let player choose character
  //generate 2 random character, this two can't be identical
  CRandomCharacterPool * CharacterPool = new CRandomCharacterPool;
  for(std::vector<CPlayer *>::iterator it = room->GetPlayerList().begin();it != room->GetPlayerList().end();++it)
  {
    (*it)->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapStartGame(room, 1).dump());
    CharacterPool->FlushChoicePool();
    std::vector<std::string> CharacterChoicePool = CharacterPool->ChoiceCharacterFromPool();
    //hard code to have 2 character
    (*it)->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapChooseCharacter(CharacterChoicePool[0], CharacterChoicePool[1]).dump());
    CharacterPool->RemoveChoiceFromPool();
  }
  //loop to check if everybody has character card
  room->LoopToCheckHaveCharacter();
  //auto choose team for player, tbc
  room->AutoChooseTeam();
  //choose Sergent as the first player
  CPlayer * CurrentPlayer;
  for(std::vector<CPlayer *>::iterator it = room->GetPlayerList().begin();it != room->GetPlayerList().end();++it)
  {
    if((*it)->GetIdentity() == Team::Sergeant)
    {
      CurrentPlayer = *it;
    }
  }
  room->InitPlayerState();
  WinCondition GameEndState;
  //loop while game isn't end, GameEndState record what team win
  while((GameEndState = room->isGameEnd()) == WinCondition::None)
  {
    //Draw card stage
    CurrentPlayer->DrawCard(room);
    room->UpdatePlayerPublicInfo();
    //inform user that it's his/her turn
    CurrentPlayer->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapConfirm(8).dump());
    CurrentPlayer->SetEndUsingCard(false);
    while(!CurrentPlayer->isEndUsingCard())
    {
      //Use card stage
    }
    room->UpdatePlayerPublicInfo();
    CurrentPlayer->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapConfirm(13).dump());
    if(CurrentPlayer->GetHoldingAmount() > CurrentPlayer->GetHP())
    {
      CurrentPlayer->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapFoldAmount(CurrentPlayer->GetHoldingAmount() - CurrentPlayer->GetHP()).dump());
      while(CurrentPlayer->GetHoldingAmount() > CurrentPlayer->GetHP())
      {
        //Fold card stage
      }
      room->UpdatePlayerPublicInfo();
    }
    //init player's state
    room->InitPlayerRoundState(CurrentPlayer);
    room->GetRoomEvent()->callRoundEnd(room, CurrentPlayer);
    CurrentPlayer = room->GetNextPlayer(CurrentPlayer);
  }
  room->EndGame(GameEndState);
}
CRoom::~CRoom()
{
  for(std::vector<CPlayer *>::iterator it = playerList.begin();it != playerList.end();)
  {
    delete *it;
    it = playerList.erase(it);
  }
  delete this->plague;
  delete this->discardPlague;
  delete this->RoomEvent;
}
