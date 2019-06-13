#include "CardGenDecorator.h"
#include "CardGenFactory.h"
#include "Room.h"
std::vector<CCard *> & CCardGenComponent::GetGeneratePlague()
{
  return Plague;
}
CCardGenConcreteComponent::CCardGenConcreteComponent(CRoom * room)
{
  Plague.push_back(NSCardGenFactory::createCard("Winchester", room, 1, Suit::Diamond));
  Plague.push_back(NSCardGenFactory::createCard("Winchester", room, 7, Suit::Spade));
  Plague.push_back(NSCardGenFactory::createCard("Barrel", room, 5, Suit::Heart));
  Plague.push_back(NSCardGenFactory::createCard("Barrel", room, 8, Suit::Diamond));
  Plague.push_back(NSCardGenFactory::createCard("Carabine", room, 7, Suit::Spade));
  Plague.push_back(NSCardGenFactory::createCard("Carabine", room, 2, Suit::Heart));
  Plague.push_back(NSCardGenFactory::createCard("Mustang", room, 3, Suit::Heart));
  Plague.push_back(NSCardGenFactory::createCard("Mustang", room, 8, Suit::Diamond));
  Plague.push_back(NSCardGenFactory::createCard("Remington", room, 9, Suit::Diamond));
  Plague.push_back(NSCardGenFactory::createCard("Remington", room, 4, Suit::Club));
  Plague.push_back(NSCardGenFactory::createCard("Saloon", room, 12, Suit::Diamond));
  Plague.push_back(NSCardGenFactory::createCard("Saloon", room, 10, Suit::Heart));
  Plague.push_back(NSCardGenFactory::createCard("Schofield", room, 13, Suit::Club));
  Plague.push_back(NSCardGenFactory::createCard("Schofield", room, 11, Suit::Spade));
  Plague.push_back(NSCardGenFactory::createCard("Volcanic", room, 2, Suit::Club));
  Plague.push_back(NSCardGenFactory::createCard("Volcanic", room, 5, Suit::Spade));
  Plague.push_back(NSCardGenFactory::createCard("Stagecoach", room, 8, Suit::Heart));
  Plague.push_back(NSCardGenFactory::createCard("Stagecoach", room, 1, Suit::Heart));
  Plague.push_back(NSCardGenFactory::createCard("Wells fargo", room, 11, Suit::Diamond));
  Plague.push_back(NSCardGenFactory::createCard("Wells fargo", room, 7, Suit::Heart));
  Plague.push_back(NSCardGenFactory::createCard("Jail", room, 9, Suit::Club));
  Plague.push_back(NSCardGenFactory::createCard("Jail", room, 4, Suit::Spade));
  Plague.push_back(NSCardGenFactory::createCard("Bang!", room, 5, Suit::Diamond));
  Plague.push_back(NSCardGenFactory::createCard("Bang!", room, 6, Suit::Heart));
  Plague.push_back(NSCardGenFactory::createCard("Bang!", room, 7, Suit::Club));
  Plague.push_back(NSCardGenFactory::createCard("Bang!", room, 8, Suit::Spade));
  Plague.push_back(NSCardGenFactory::createCard("Missed!", room, 9, Suit::Diamond));
  Plague.push_back(NSCardGenFactory::createCard("Missed!", room, 10, Suit::Heart));
  Plague.push_back(NSCardGenFactory::createCard("Missed!", room, 11, Suit::Club));
  Plague.push_back(NSCardGenFactory::createCard("Missed!", room, 12, Suit::Spade));
  Plague.push_back(NSCardGenFactory::createCard("Indians!", room, 9, Suit::Heart));
  Plague.push_back(NSCardGenFactory::createCard("Indians!", room, 4, Suit::Club));
  Plague.push_back(NSCardGenFactory::createCard("Gatling", room, 9, Suit::Diamond));
  Plague.push_back(NSCardGenFactory::createCard("Gatling", room, 9, Suit::Spade));
  Plague.push_back(NSCardGenFactory::createCard("Duel", room, 3, Suit::Diamond));
  Plague.push_back(NSCardGenFactory::createCard("Duel", room, 4, Suit::Club));
  Plague.push_back(NSCardGenFactory::createCard("Beer", room, 9, Suit::Heart));
  Plague.push_back(NSCardGenFactory::createCard("Beer", room, 10, Suit::Diamond));
  Plague.push_back(NSCardGenFactory::createCard("Panic!", room, 1, Suit::Club));
  Plague.push_back(NSCardGenFactory::createCard("Panic!", room, 7, Suit::Heart));
  Plague.push_back(NSCardGenFactory::createCard("Cat Balou", room, 2, Suit::Spade));
  Plague.push_back(NSCardGenFactory::createCard("Cat Balou", room, 9, Suit::Club));
  Plague.push_back(NSCardGenFactory::createCard("Dynamite", room, 4, Suit::Diamond));
  Plague.push_back(NSCardGenFactory::createCard("Dynamite", room, 3, Suit::Heart));
}
CCardGenDecorator::CCardGenDecorator(CCardGenComponent * Component)
{
  this->Component = Component;
}
CCardGenConcreteDecoratorGeneralStore::CCardGenConcreteDecoratorGeneralStore(CCardGenComponent * Component, CRoom * room) : CCardGenDecorator(Component)
{
  this->Component->GetGeneratePlague().push_back(NSCardGenFactory::createCard("General Store", room, 1, Suit::Club));
  this->Component->GetGeneratePlague().push_back(NSCardGenFactory::createCard("General Store", room, 7, Suit::Spade));
}
std::vector<CCard *> & CCardGenDecorator::GetGeneratePlague()
{
  return this->Component->GetGeneratePlague();
}
