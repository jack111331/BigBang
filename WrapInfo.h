#pragma once

#include "User.h"
#include "nlohmann/json.hpp"
#include <string>
namespace NSWrapInfo
{
  nlohmann::json WrapUserInfo(CUser * user);
  nlohmann::json WrapLoungeSetInfo();
  nlohmann::json WrapConfirm(int action);
  nlohmann::json WrapStartGameFail();
  nlohmann::json WrapChooseCharacter(std::string CharacterName_1, std::string CharacterName_2);
  nlohmann::json WrapPublicGameInfo(CRoom * room, CPlayer * player);
  nlohmann::json WrapFoldAmount(int amount);
  nlohmann::json WrapEndGame(CRoom * room);
}
