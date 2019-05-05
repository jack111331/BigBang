#pragma once

#include "User.h"
#include "nlohmann/json.hpp"
namespace NSWrapInfo
{
  nlohmann::json WrapUserInfo(CUser * user);
}
