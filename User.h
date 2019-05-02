#pragma once
#include <stdint.h>
#include <string>
#include "HandleMessage.h"
#include "HandleClientSocket.h"
class CUser
{
public:
  CUser();
  void RetriveDataFromDB();
  void SetID(uint32_t ID);
  std::string GetName();
  int GetMoney();
  int GetWin();
  int GetLose();
  uint32_t GetID();
  void SetSocketIO(CHandleClientSocket * ClientSocket);
  CHandleClientSocket * GetSocketIO();
  ~CUser();
private:
  std::string name;
  int money;
  int win;
  int lose;
  uint32_t ID;
  CHandleClientSocket * SocketIO;
};
