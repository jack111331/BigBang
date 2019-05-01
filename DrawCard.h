#pragma once

class CPlayer;

class IDrawCardFromPlayer
{
public:
  virtual void DrawCard(CPlayer * drawer, CPlayer * drawee) = 0;
};
class CDrawCardFromPlayer
{
public:
  CDrawCardFromPlayer(IDrawCardFromPlayer *);
  void DrawCardFromPlayer(CPlayer * drawer, CPlayer * drawee);
private:
  IDrawCardFromPlayer * Strategy;
};
class CChooseCard : public IDrawCardFromPlayer
{
public:
  void DrawCard(CPlayer * drawer, CPlayer * drawee);
};
class CRandomChooseCard : public IDrawCardFromPlayer
{
public:
  void DrawCard(CPlayer * drawer, CPlayer * drawee);
};
