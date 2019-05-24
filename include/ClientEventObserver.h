#pragma once
#include <map>
#include "User.h"
class CClientEventObserver
{
public:
  static void registerOnConnect(void (*ConnectFunction)(CUser * user));
  static void registerOnDisconnect(void (*DisconnectFunction)(CUser * user));
  static void CallConnect(CUser * user);
  static void CallDisconnect(CUser * user);
  static void unregisterOnConnect(void (*ConnectFunction)(CUser * user));
  static void unregisterOnDisconnect(void (*DisconnectFunction)(CUser * user));
private:
  static std::map<void (*)(CUser * user), int> ConnectListener;
  static std::map<void (*)(CUser * user), int> DisconnectListener;
};
