#include "HandleMessage.h"
#include "User.h"
#include "nlohmann/json.hpp"
#include <stdint.h>

using json = nlohmann::json;

void RetriveUserIDWithData(const json & Content, CUser * user)
{
  uint32_t UserID;
  Content.at("UserID").get_to(UserID);
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
    case 1:
    {
      RetriveUserIDWithData(Content, user);
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
