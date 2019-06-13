#pragma once

#include "User.h"
#include "nlohmann/json.hpp"
#include <string>
#include <vector>
class CPlayer;
class CRoom;
class CCard;
class CExclusiveCardInventory;
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
  nlohmann::json WrapLoungeInfo(uint32_t ID);
  nlohmann::json WrapWhoUseCard(CPlayer * User, uint32_t CardID);
  nlohmann::json WrapTalkMessage(int Position, const nlohmann::json & Content);
  nlohmann::json WrapStoreInfo();
  nlohmann::json WrapBuyCardSuccess(bool Success);
  nlohmann::json WrapUserHaveExclusiveCard(CExclusiveCardInventory * ExclusiveCardInventory);
  nlohmann::json WrapChooseCardInfo(std::vector<CCard *> & ChooseCardList);
}
