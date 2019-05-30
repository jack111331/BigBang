#include "Player.h"
#include "Action.h"
#include "Room.h"
#include "User.h"
void CPlayer::DrawCard(CRoom * room)
{
  if(Character != nullptr)
  {
    if(room->GetRoomEvent()->callDrawCard(room, this))
    {
      Character->DrawCard(room, this);
    }
  }
}

void CPlayer::Attack(CRoom * room, CPlayer * target)
{
  if(Character != nullptr)
  {
    Character->Attack(room, this, target);
  }
}
void CPlayer::UseCard(CRoom * room, int cardID, CPlayer * target)
{
  CCard * card = GetCardInHolding(cardID);
  if(card)
  {
    puts("Use Card");
    card->UseCardEffect(room, this, target);
    puts("Used Card");
    RemoveHolding(card);
  }
}
void CPlayer::FoldCard(CRoom * room, int cardID)
{
  CCard * card = GetCardInHolding(cardID);
  if(card)
  {
    NSAction::FoldCard(this, card, room->GetDiscardPlague());
  }
}
void CPlayer::GetCard(uint32_t cardID)
{
  CCard * card = GetCardInHolding(cardID);
  if(card)
  {
    AddHolding(card);
  }
}
void CPlayer::RemoveCard(uint32_t cardID)
{
  CCard * card = GetCardInHolding(cardID);
  if(card)
  {
    RemoveHolding(card);
  }
}

CUser * CPlayer::GetUser()
{
  return this->User;
}
CCharacter * CPlayer::GetCharacter()
{
  return this->Character;
}
Team CPlayer::GetIdentity() const
{
  return this->Identity;
}
int CPlayer::GetHP() const
{
  return this->HP;
}
int CPlayer::GetMaxHP() const
{
  return this->MaxHP;
}
const std::vector<CCard *> & CPlayer::GetHolding() const
{
  return this->Holding;
}
CCard * CPlayer::GetRandomHolding()
{
  std::vector<CCard *>::iterator it = Holding.begin();
  srand(time(0));
  std::advance(it, rand() % static_cast<int>(Holding.size()));
  return *it;
}
int CPlayer::GetHoldingAmount() const
{
  return static_cast<int>(this->Holding.size());
}
const CCard * CPlayer::GetEquipment() const
{
  return this->Equipment;
}
int CPlayer::GetPosition() const
{
  return this->Position;
}
bool CPlayer::isAttacked() const
{
  return this->Attacked;
}
bool CPlayer::isDead() const
{
  return this->Dead;
}
bool CPlayer::isHasMultiAttack() const
{
  return this->HasMultiAttack;
}

int CPlayer::GetAttackRange() const
{
  return this->AttackRange;
}
int CPlayer::GetAddRange() const
{
  return this->AddRange;
}
int CPlayer::GetMinusRange() const
{
  return this->MinusRange;
}
int CPlayer::BusyWaiting(int Action)
{
  while(this->User->GetHandledAction() != Action);
  return this->User->GetActionResult();
}

void CPlayer::SetUser(CUser * user)
{
  this->User = user;
}
void CPlayer::SetCharacter(CCharacter * character)
{
  this->Character = character;
  SetMaxHP(character->GetMaxHP());
  SetAttackRange(character->GetDefaultAttackRange());
  SetAddRange(character->GetDefaultAddRange());
  SetMinusRange(character->GetDefaultMinusRange());
  SetMultiAttack(character->GetDefaultMultiAttack());
}
void CPlayer::SetIdentity(Team identity)
{
  this->Identity = identity;
}
void CPlayer::SetHP(int HP)
{
  this->HP = std::max(HP, 0);
}
void CPlayer::SetMaxHP(int maxHP)
{
  this->MaxHP = maxHP;
}
void CPlayer::AddHolding(CCard * card)
{
  Holding.push_back(card);
}
CCard * CPlayer::GetCardInHolding(std::string cardname)
{
  for(int i = 0;i < static_cast<int>(Holding.size());i++)
  {
    if(Holding[i]->GetName() == cardname)
    {
      return Holding[i];
    }
  }
  return nullptr;
}
CCard * CPlayer::GetCardInHolding(int cardID)
{
  for(int i = 0;i < static_cast<int>(Holding.size());i++)
  {
    if(Holding[i]->GetID() == cardID)
    {
      return Holding[i];
    }
  }
  return nullptr;
}
void CPlayer::RemoveHolding(const CCard * card)
{
  for(std::vector<CCard *>::iterator it = Holding.begin();it != Holding.end();++it)
  {
    if((*it)->GetID() == card->GetID())
    {
      Holding.erase(it);
      break;
    }
  }
}
void CPlayer::ChangeEquipment(CCard * equipment)
{
  this->Equipment = equipment;
}
void CPlayer::SetPosition(int position)
{
  this->Position = position;
}
void CPlayer::SetAttacked(bool attacked)
{
  this->Attacked = attacked;
}
void CPlayer::SetDead(bool dead)
{
  this->Dead = dead;
}
void CPlayer::SetMultiAttack(bool HasMultiAttack)
{
  this->HasMultiAttack = HasMultiAttack;
}
void CPlayer::SetAttackRange(int attackRange)
{
  this->AttackRange = attackRange;
}
void CPlayer::SetAddRange(int addRange)
{
  this->AddRange = addRange;
}
void CPlayer::SetMinusRange(int minusRange)
{
  this->MinusRange = minusRange;
}
CPlayer::~CPlayer()
{
  delete this->Character;
  for(std::vector<CCard *>::iterator it = this->Holding.begin();it != this->Holding.end();)
  {
    it = Holding.erase(it);
  }
  delete this->Equipment;
}
