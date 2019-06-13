#pragma once
#include <vector>
class CCard;
class CRoom;
class CCardGenComponent
{
public:
  virtual std::vector<CCard *> GetGeneratePlague();
protected:
  std::vector<CCard *> Plague;
};
class CCardGenConcreteComponent : public CCardGenComponent
{
public:
  CCardGenConcreteComponent(CRoom * room);
};

class CCardGenDecorator : public CCardGenComponent
{
public:
  CCardGenDecorator(CCardGenComponent * Component);
  std::vector<CCard *> GetGeneratePlague();
protected:
  CCardGenComponent * Component;
};

class CCardGenConcreteDecoratorGeneralStore : public CCardGenDecorator
{
public:
  CCardGenConcreteDecoratorGeneralStore(CCardGenComponent * Component, CRoom * room);
};
