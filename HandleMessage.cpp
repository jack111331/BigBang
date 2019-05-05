#include "HandleMessage.h"
#include "User.h"
#include "nlohmann/json.hpp"
#include "WrapInfo.h"
#include <stdint.h>

using json = nlohmann::json;

void RetriveUserRegisterInfo(const json & Content, CUser * user)
{
  uint32_t UserID = Content["User ID"];
  user->SetID(UserID);
  user->SetName(Content["Nick Name"]);
  user->SetMoney(20);
  user->SetWin(0);
  user->SetLose(0);
}
void RetriveUserIDWithData(const json & Content, CUser * user)
{
  uint32_t UserID = Content["User ID"];
  user->SetID(UserID);
  user->RetriveDataFromDB();
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
      RetriveUserRegisterInfo(Content, user);
      user->SendMessage("Send Message", NSWrapInfo::WrapUserInfo(user).dump());
      break;
    }
    case 1:
    {
      RetriveUserIDWithData(Content, user);
      user->SendMessage("Send Message", NSWrapInfo::WrapUserInfo(user).dump());
      break;
    }
    case 2:
    {
      break;
    }
    default:
    {

    }
  }
}
