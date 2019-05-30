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
#include "Database.h"

using json = nlohmann::json;

void RetrieveUserID(const json & Content, CUser * user)
{
  uint32_t UserID = Content["User ID"];
  user->SetID(UserID);
  user->SetMoney(20);
  user->SetWin(0);
  user->SetLose(0);
  user->RetriveDataFromDB();
  user->UpdateUserInfo();
  CLoungeManage::getInstance()->addUserToNewLounge(user);
}
void RetrieveUserNickName(const json & Content, CUser * user)
{
  std::string UserNickName = Content["Nick Name"];
  user->SetName(UserNickName);
  user->UpdateUserInfo();
}
uint32_t RetrieveJoinLoungeID(const json & Content)
{
  return Content["Lounge ID"];
}
uint32_t RetrieveJoinUserID(const json & Content)
{
  return Content["User ID"];
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
  printf("Receive:\n%s\n", Message);
  json Content = json::parse(Message);
  int Action;
  Action = Content["Action"];
  switch(Action)
  {
    case 0:
    {
      RetrieveUserID(Content, user);
      user->SendMessage("Send Message", NSWrapInfo::WrapUserInfo(user).dump());
      break;
    }
    case 1:
    {
      RetrieveUserNickName(Content, user);
      user->SendMessage("Send Message", NSWrapInfo::WrapConfirm(1).dump());
      break;
    }
    case 2:
    {
      user->SendMessage("Send Message", NSWrapInfo::WrapLoungeSetInfo().dump());
      break;
    }
    case 3:
    {
      CLoungeManage::getInstance()->removeUserFromLounge(user);
      bool JoinMethod = Content["Join Method"];
      if(JoinMethod)
      {
        CLoungeManage::getInstance()->addUserToLounge(user, RetrieveJoinLoungeID(Content));
      }
      else
      {
        CLoungeManage::getInstance()->addUserToLounge(user, CLoungeManage::getInstance()->searchLoungeByUserID(RetrieveJoinUserID(Content)));
      }
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
      if(user != UserLounge->getRoomOwner())
      {
        //can't let not-room-owner start game
        user->SendMessage("Send Message", NSWrapInfo::WrapStartGame(UserLounge->getRoom(), 0).dump());
        break;
      }
      bool StartGame = UserLounge->startGame();
      if(!StartGame)
      {
        user->SendMessage("Send Message", NSWrapInfo::WrapStartGame(UserLounge->getRoom(), 0).dump());
      }
      break;
    }
    case 6:
    {
      CLounge * UserLounge = CLoungeManage::getInstance()->searchLounge(user);
      user->GetPlayer()->SetCharacter(NSCharacterGenFactory::createCharacter(RetrieveChooseCharacter(Content), UserLounge->getRoom()));
      break;
    }
    case 9:
    {
      CLounge * UserLounge = CLoungeManage::getInstance()->searchLounge(user);
      int UseCardID = Content["Card ID"];
      int TargetPosition = Content["Target Position"];
      user->GetPlayer()->UseCard(UserLounge->getRoom(), UseCardID, UserLounge->getRoom()->GetPlayerByPosition(TargetPosition));
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
      int CardID = Content["Choose Card ID"];
      bool ChooseOrDiscard = Content["Choose or Discard"];
      if(ChooseOrDiscard)
      {
        NSAction::GiveCard(Chooser, Choosee, CardID);
      }
      else
      {
        NSAction::FoldCard(Choosee, Choosee->GetCardInHolding(CardID), UserLounge->getRoom()->GetDiscardPlague());
      }
      break;
    }
    case 12:
    {
      user->SendMessage("Handled Data Result", std::to_string(static_cast<int>(Content["Revolt"])));
      break;
    }
    case 13:
    {
      break;
    }
    case 14:
    {
      CLounge * UserLounge = CLoungeManage::getInstance()->searchLounge(user);
      std::vector<json> FoldCardJSONList = Content["Fold Card"];
      for(int i = 0;i < static_cast<int>(FoldCardJSONList.size());++i)
      {
        user->GetPlayer()->FoldCard(UserLounge->getRoom(), FoldCardJSONList[i]["ID"]);
      }
      break;
    }
    case 17:
    {
      user->SendMessage("Send Message", NSWrapInfo::WrapFriendList(user->GetID()).dump());
      break;
    }
    case 18:
    {
      uint32_t FriendID = Content["Friend ID"];
      CDatabase DB;
      int result = 0;
      if(user->GetID() != FriendID)
      {
        result = DB.InsertFriend(user->GetID(), FriendID);
      }
      user->SendMessage("Send Message", NSWrapInfo::WrapAddFriendMessage(result).dump());
      break;
    }
    case 21:
    {
      CLoungeManage::getInstance()->removeUserFromLounge(user);
      CLoungeManage::getInstance()->addUserToNewLounge(user);
      break;
    }
    case 22:
    {
      user->SendMessage("Send Message", NSWrapInfo::WrapLoungeInfo(user->GetID()).dump());
    }
    default:
    {

    }
  }
  user->SendMessage("Handled Data", std::to_string(Action));
}
