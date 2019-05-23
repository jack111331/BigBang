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

void RetrieveUserRegisterInfo(const json & Content, CUser * user)
{
  uint32_t UserID = Content["User ID"];
  user->SetID(UserID);
  user->SetName(Content["Nick Name"]);
  user->SetMoney(20);
  user->SetWin(0);
  user->SetLose(0);
  CLoungeManage::getInstance()->addUserToNewLounge(user);
}
void RetrieveUserIDWithData(const json & Content, CUser * user)
{
  uint32_t UserID = Content["User ID"];
  user->SetID(UserID);
  user->RetriveDataFromDB();
  CLoungeManage::getInstance()->addUserToNewLounge(user);
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
      std::string UseCardName = Content["Card Name"];
      int TargetPosition = Content["Target Position"];
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
    case 17:
    {
      user->SendMessage("Send Message", NSWrapInfo::WrapFriendList(user->GetID()).dump());
      break;
    }
    case 18:
    {
      uint32_t FriendID = Content["Friend ID"];
      CDatabase DB;
      DB.ConnectToDatabase();
      DB.InsertFriend(user->GetID(), FriendID);
      break;
    }
    default:
    {

    }
  }
}
