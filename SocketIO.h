#ifndef SOCKETIO_H
  #define SOCKETIO_H
  class ISocketIO
  {
  public:
    virtual bool Receive() = 0;
    virtual const char * GetReceiveBuffer() const = 0;
    virtual bool Send(const char * Buffer) = 0;
  };
  #endif
