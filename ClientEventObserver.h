#pragma once
#include <vector>
class CClientEventObserver
{
public:
  void registerOnConnect(void (*ConnectFunction)());
  void registerOnDisconnect(void (*DisconnectFunction)());
  void CallConnect();
  void CallDisconnect();
  void unregisterOnConnect(void (*ConnectFunction)());
  void unregisterOnDisconnect(void (*DisconnectFunction)());
private:
  std::vector<void (*)()> ConnectListener;
  std::vector<void (*)()> DisconnectListener;
};
