#include "HandleMessage.h"
#include "User.h"
#include "nlohmann/json.hpp"
#include "WrapInfo.h"
#include "CharacterGenFactory.h"
#include "LoungeManage.h"
#include <stdint.h>
#include <string>
#include <vector>

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
//          it->SendMessage("Send Message", NSWrapInfo::WrapGameStartInfo().dump());
        }
      }
      else
      {
        user->SendMessage("Send Message", NSWrapInfo::WrapStartGameFail().dump());
      }
      break;
    }
    case 6:
    {
      user->GetPlayer()->SetCharacter(NSCharacterGenFactory::createCharacter(RetrieveChooseCharacter(Content)));
      break;
    }
    default:
    {

    }
  }
}
