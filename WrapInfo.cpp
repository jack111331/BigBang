#include "WrapInfo.h"

using json = nlohmann::json;

json NSWrapInfo::WrapUserInfo(CUser * user)
{
  json Buffer;
  Buffer["Action"] = 1;
  Buffer["Nick Name"] = user->GetName();
  Buffer["User Money"] = user->GetMoney();
  Buffer["User Win"] = user->GetWin();
  Buffer["User Lose"] = user->GetLose();
  return Buffer;
}
