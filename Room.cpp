#include "Room.h"
#include "User.h"
#include "CharacterGenFactory.h"
#include "WrapInfo.h"
#include "Action.h"
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
  player->SetPosition(static_cast<int>(playerList.size()));
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
  /*
  Sergeant = 0, //警長
  ChiefSergeant, //副警長
  BadAss, //歹徒
  Traitor //叛徒
  */
  int TeamSurviveAmount[4] = {};
  for(std::vector<CPlayer *>::iterator it = GetPlayerList().begin();it != GetPlayerList().end();++it)
  {
    if(!(*it)->isDead())
    {
      TeamSurviveAmount[static_cast<int>((*it)->GetIdentity())]++;
    }
  }
  if(!TeamSurviveAmount[static_cast<int>(Team::Sergeant)])
  {
    return WinCondition::SergeantWin;
  }
  else if(!TeamSurviveAmount[static_cast<int>(Team::BadAss)] && !TeamSurviveAmount[static_cast<int>(Team::Traitor)])
  {
    return WinCondition::BadAssWin;
  }
  else if(!TeamSurviveAmount[static_cast<int>(Team::Sergeant)] && !TeamSurviveAmount[static_cast<int>(Team::ChiefSergeant)] && !TeamSurviveAmount[static_cast<int>(Team::BadAss)])
  {
    return WinCondition::TraitorWin;
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
void CRoom::UpdatePlayerPublicInfo()
{
  for(std::vector<CPlayer *>::iterator it = playerList.begin();it != playerList.end();++it)
  {
    //update player's info
    (*it)->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapPublicGameInfo(this, *it));
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
      NSAction::DrawCardFromPlague(plague, *it);
    }
  }
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
    (*it)->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapEndGame(this));
    if(((*it)->GetIdentity() == Team::Sergeant || (*it)->GetIdentity() == Team::ChiefSergeant) && GameEndState == WinCondition::SergeantWin)
    {
      (*it)->GetUser()->SetWin((*it)->GetUser()->GetWin() + 1);
    }
    else if((*it)->GetIdentity() == Team::BadAss && GameEndState == WinCondition::BadAssWin)
    {
      (*it)->GetUser()->SetWin((*it)->GetUser()->GetWin() + 1);
    }
    else if((*it)->GetIdentity() == Team::Traitor && GameEndState == WinCondition::TraitorWin)
    {
      (*it)->GetUser()->SetWin((*it)->GetUser()->GetWin() + 1);
    }
    else
    {
      (*it)->GetUser()->SetLose((*it)->GetUser()->GetLose() + 1);
    }
  }
  // post process some thing..
}

void CRoom::GameLoop(CRoom * room)
{
  //let player choose card
  //generate 2 random character, this two can't be identical
  CRandomCharacterPool * CharacterPool = new CRandomCharacterPool;
  for(std::vector<CPlayer *>::iterator it = room->GetPlayerList().begin();it != room->GetPlayerList().end();++it)
  {
    (*it)->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapStartGame(room, 1));


    std::vector<std::string> CharacterChoicePool = CharacterPool->ChoiceCharacterFromPool();
    //hard code to have 2 character
    (*it)->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapChooseCharacter(CharacterChoicePool[0], CharacterChoicePool[1]));
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
    CurrentPlayer->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapConfirm(8));
    while(!CurrentPlayer->isEndUsingCard())
    {
      //Use card stage
    }
    room->UpdatePlayerPublicInfo();
    CurrentPlayer->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapConfirm(13));
    if(CurrentPlayer->GetHoldingAmount() > CurrentPlayer->GetHP())
    {
      CurrentPlayer->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapFoldAmount(CurrentPlayer->GetHoldingAmount() - CurrentPlayer->GetHP()));
      while(CurrentPlayer->GetHoldingAmount() > CurrentPlayer->GetHP())
      {
        //Fold card stage
      }
      room->UpdatePlayerPublicInfo();
    }
    //init player's state
    room->InitPlayerRoundState(CurrentPlayer);
    CurrentPlayer = room->GetNextPlayer(CurrentPlayer);
  }
  room->EndGame(GameEndState);
}
CRoom::~CRoom()
{
  for(std::vector<CPlayer *>::iterator it = playerList.begin();it != playerList.end();++it)
  {
    delete *it;
  }
  playerList.clear();
}
