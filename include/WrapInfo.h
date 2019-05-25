#pragma once

#include "User.h"
#include "nlohmann/json.hpp"
#include <string>
class CPlayer;
class CRoom;
class CCard;
namespace NSWrapInfo
{
  nlohmann::json WrapUserInfo(CUser * user);
  nlohmann::json WrapLoungeSetInfo();
  nlohmann::json WrapConfirm(int action);
  nlohmann::json WrapStartGame(CRoom * room, int success);
  nlohmann::json WrapChooseCharacter(std::string CharacterName_1, std::string CharacterName_2);
  nlohmann::json WrapPublicGameInfo(CRoom * room, CPlayer * player);
  nlohmann::json WrapShowCard(CPlayer * shower, CPlayer * showee);
  nlohmann::json WrapChooseCard(CPlayer * chooser, CPlayer * choosee, bool ChooseOrDiscard);
  nlohmann::json WrapRevoltCard(CCard * card);
  nlohmann::json WrapFoldAmount(int amount);
  nlohmann::json WrapEndGame(bool WinOrLose);
  nlohmann::json WrapFriendList(uint32_t ID);
  nlohmann::json WrapAddFriendMessage(int Result);
  nlohmann::json WrapDetermineCard(int CardID);
}
