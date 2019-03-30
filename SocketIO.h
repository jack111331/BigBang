#pragma once

class ISocketIO
{
public:
  virtual const char * Receive() = 0;
  virtual bool Send(const char * Buffer) = 0;
};
