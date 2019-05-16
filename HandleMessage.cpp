#include "HandleMessage.h"
#include "User.h"
#include "nlohmann/json.hpp"
#include "WrapInfo.h"
#include "CharacterGenFactory.h"
#include "LoungeManage.h"
#include <stdint.h>
#include <string>
#include <vector>
#include "Action.h"
#include "Room.h"

using json = nlohmann::json;

void RetrieveUserRegisterInfo(const json & Content, CUser * user)
{
  uint32_t UserID = Content["User ID"];
  user->SetID(UserID);
  user->SetName(Content["Nick Name"]);
  user->SetMoney(20);
  user->SetWin(0);
  user->SetLose(0);
}
void RetrieveUserIDWithData(const json & Content, CUser * user)
{
  uint32_t UserID = Content["User ID"];
  user->SetID(UserID);
  user->RetriveDataFromDB();
}
uint32_t RetrieveJoinLoungeID(const json & Content)
{
  return Content["Lounge ID"];
}
bool RetrieveReadyState(const json & Content)
{
  return Content["Ready"];
}
std::string RetrieveChooseCharacter(const json & Content)
{
  return Content["Choose Character Name"];
}
void BlockHandleMessage(CUser * User)
{

}
void NSHandleMessage::HandleMessage(const char * Message, CUser * user)
{
  json Content = json::parse(Message);
  int Action;
  Content.at("Action").get_to(Action);
  switch(Action)
  {
    case 0:
    {
      RetrieveUserRegisterInfo(Content, user);
      user->SendMessage("Send Message", NSWrapInfo::WrapUserInfo(user).dump());
      break;
    }
    case 1:
    {
      RetrieveUserIDWithData(Content, user);
      user->SendMessage("Send Message", NSWrapInfo::WrapUserInfo(user).dump());
      break;
    }
    case 2:
    {
      user->SendMessage("Send Message", NSWrapInfo::WrapLoungeSetInfo().dump());
      break;
    }
    case 3:
    {
      CLoungeManage::getInstance()->addUserToLounge(user, RetrieveJoinLoungeID(Content));
      user->SendMessage("Send Message", NSWrapInfo::WrapConfirm(3).dump());
      break;
    }
    case 4:
    {
      CLoungeManage::getInstance()->searchLounge(user)->setReadyState(user, RetrieveReadyState(Content));
      user->SendMessage("Send Message", NSWrapInfo::WrapConfirm(4).dump());
      break;
    }
    case 5:
    {
      CLounge * UserLounge = CLoungeManage::getInstance()->searchLounge(user);
      bool StartGame = UserLounge->startGame();
      if(StartGame)
      {
        std::vector<CUser *> AllUser = UserLounge->GetAllUser();
        for(std::vector<CUser *>::iterator it = AllUser.begin();it != AllUser.end();++it)
        {
          (*it)->SendMessage("Send Message", NSWrapInfo::WrapStartGame(UserLounge->getRoom(), 1).dump());
        }
      }
      else
      {
        user->SendMessage("Send Message", NSWrapInfo::WrapStartGame(UserLounge->getRoom(), 0).dump());
      }
      break;
    }
    case 6:
    {
      user->GetPlayer()->SetCharacter(NSCharacterGenFactory::createCharacter(RetrieveChooseCharacter(Content)));
      break;
    }
    case 9:
    {
      CLounge * UserLounge = CLoungeManage::getInstance()->searchLounge(user);
      std::string UseCardName = Content["Card Name"];
      uint32_t TargetPosition = Content["Target Position"];
      user->GetPlayer()->UseCard(UserLounge->getRoom(), UseCardName, UserLounge->getRoom()->GetPlayerByPosition(TargetPosition));
      std::vector<CUser *> AllUser = UserLounge->GetAllUser();
      for(std::vector<CUser *>::iterator it = AllUser.begin();it != AllUser.end();++it)
      {
        (*it)->SendMessage("Send Message", NSWrapInfo::WrapPublicGameInfo(UserLounge->getRoom(), (*it)->GetPlayer()).dump());
      }
      break;
    }
    case 11:
    {
      CLounge * UserLounge = CLoungeManage::getInstance()->searchLounge(user);
      CPlayer * Chooser = UserLounge->getRoom()->GetPlayerByPosition(Content["Chooser Position"]);
      CPlayer * Choosee = UserLounge->getRoom()->GetPlayerByPosition(Content["Choosee Position"]);
      uint32_t GiveCardID = Content["Choose Card ID"];
      NSAction::GiveCard(Chooser, Choosee, GiveCardID);
      user->GetPlayer()->SetEndChooseCard(true);
      break;
    }
    case 12:
    {
      user->GetPlayer()->SetRevolt(Content["Revolt"]);
      break;
    }
    case 13:
    {
      user->GetPlayer()->SetEndUsingCard(true);
      break;
    }
    case 14:
    {
      int FoldCardAmount = Content["Fold Card Amount"];
      CLounge * UserLounge = CLoungeManage::getInstance()->searchLounge(user);
      for(int i = 0;i < FoldCardAmount;i++)
      {
        user->GetPlayer()->FoldCard(UserLounge->getRoom(), Content["Fold Card " + std::to_string(i) + " ID"]);
      }
      break;
    }
    default:
    {

    }
  }
}
