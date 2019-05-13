#pragma once
#include <vector>
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
  static std::vector<void (*)(CUser * user)> ConnectListener;
  static std::vector<void (*)(CUser * user)> DisconnectListener;
};
