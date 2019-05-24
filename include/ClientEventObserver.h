#pragma once
#include <map>
#include "User.h"
class CClientEventObserver
{
public:
  void registerOnConnect(void (*ConnectFunction)(CUser * user));
  void registerOnDisconnect(void (*DisconnectFunction)(CUser * user));
  void CallConnect(CUser * user);
  void CallDisconnect(CUser * user);
  void unregisterOnConnect(void (*ConnectFunction)(CUser * user));
  void unregisterOnDisconnect(void (*DisconnectFunction)(CUser * user));
private:
  std::map<void (*)(CUser * user), int> ConnectListener;
  std::map<void (*)(CUser * user), int> DisconnectListener;
};
