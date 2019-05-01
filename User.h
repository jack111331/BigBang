#pragma once
#include <stdint.h>
class CUser
{
public:
  CUser();
  void RetriveDataFromDB();
  void SetID(uint32_t ID);
  int GetMoney();
  int GetWin();
  int GetLose();
  uint32_t GetID();
  ~CUser();
private:
  int money;
  int win;
  int lose;
  uint32_t ID;
};
