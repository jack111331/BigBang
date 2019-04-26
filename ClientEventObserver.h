#pragma once
#include <vector>
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
  std::vector<void (*)(CUser * user)> ConnectListener;
  std::vector<void (*)(CUser * user)> DisconnectListener;
};
