#pragma once
class CUser;
namespace NSHandleMessage
{
  void BlockHandleMessage(CUser * User);//for efficient
  void HandleMessage(const char * Message, CUser * User);
};
