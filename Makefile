BangServer : main.cpp Socket.o ListenSocket.o HandleClientSocket.o CommunicateFacade.o Action.o Room.o User.o Lounge.o LoungeManage.o InvokeMessage.o MessageMediator.o MessageMediatorColleague.o HandleMessage.o ClientEventObserver.o DrawCard.o DrawCardFactory.o GameEventObserver.o Player.o Plague.o Card.o EquipmentCard.o WeaponCard.o Winchester.o Character.o BartCassidy.o BlackJack.o
	g++ -Wall -lpthread -o BangServer -Iinclude main.cpp Socket.o ListenSocket.o HandleClientSocket.o CommunicateFacade.o Action.o Room.o User.o Lounge.o LoungeManage.o InvokeMessage.o MessageMediator.o MessageMediatorColleague.o HandleMessage.o ClientEventObserver.o  GameEventObserver.o Player.o Plague.o Card.o EquipmentCard.o WeaponCard.o Winchester.o Character.o BartCassidy.o BlackJack.o
	rm *.o


Socket.o: Socket.cpp
	g++ -Wall -c Socket.cpp
ListenSocket.o: ListenSocket.cpp
	g++ -Wall -c ListenSocket.cpp
HandleClientSocket.o: HandleClientSocket.cpp
	g++ -Wall -c HandleClientSocket.cpp

CommunicateFacade.o: CommunicateFacade.cpp
	g++ -Wall -c CommunicateFacade.cpp
Room.o: Room.cpp
	g++ -Wall -c Room.cpp
User.o: User.cpp
	g++ -Wall -c User.cpp

Player.o: Player.cpp
	g++ -Wall -c Player.cpp
Plague.o: Plague.cpp
	g++ -Wall -c Plague.cpp
Card.o: Card.cpp
	g++ -Wall -c Card.cpp
EquipmentCard.o: EquipmentCard.cpp
	g++ -Wall -c EquipmentCard.cpp
WeaponCard.o: WeaponCard.cpp
	g++ -Wall -c WeaponCard.cpp
Winchester.o: ./Card/Winchester.cpp
	g++ -Wall -c ./Card/Winchester.cpp

Character.o: Character.cpp
	g++ -Wall -c Character.cpp
BartCassidy.o: ./Character/BartCassidy.cpp
	g++ -Wall -c ./Character/BartCassidy.cpp
BlackJack.o: ./Character/BlackJack.cpp
	g++ -Wall -c ./Character/BlackJack.cpp

ClientEventObserver.o: ClientEventObserver.cpp
	g++ -Wall -c ClientEventObserver.cpp
GameEventObserver.o: GameEventObserver.cpp
	g++ -Wall -c GameEventObserver.cpp
Action.o: Action.cpp
	g++ -Wall -c Action.cpp
MessageMediator.o: MessageMediator.cpp
	g++ -Wall -c MessageMediator.cpp
MessageMediatorColleague.o: MessageMediatorColleague.cpp
	g++ -Wall -c MessageMediatorColleague.cpp
	
Lounge.o: Lounge.cpp
	g++ -Wall -c Lounge.cpp
LoungeManage.o: LoungeManage.cpp
	g++ -Wall -c LoungeManage.cpp
InvokeMessage.o: InvokeMessage.cpp
	g++ -Wall -c InvokeMessage.cpp
HandleMessage.o: HandleMessage.cpp
	g++ -Wall -Iinclude -c HandleMessage.cpp
DrawCard.o: DrawCard.cpp
	g++ -Wall -c DrawCard.cpp
DrawCardFactory.o: DrawCardFactory.cpp
	g++ -Wall -c DrawCardFactory.cpp
