COBJECTFLAG = -Wall -c -Iinclude
CFLAG = -Wall -pthread -Iinclude

BangServer : main.cpp Socket.o ListenSocket.o HandleClientSocket.o CommunicateFacade.o Action.o Room.o User.o Lounge.o LoungeManage.o MessageMediator.o MessageMediatorColleague.o WrapInfo.o HandleMessage.o ClientEventObserver.o DrawCard.o DrawCardFactory.o GameEventObserver.o Player.o Plague.o Card.o EquipmentCard.o WeaponCard.o CardGenFactory.o Winchester.o Character.o CharacterGenFactory.o BartCassidy.o BlackJack.o
	g++ -Wall -pthread -o BangServer -Iinclude main.cpp Socket.o ListenSocket.o HandleClientSocket.o CommunicateFacade.o Action.o Room.o User.o Lounge.o LoungeManage.o MessageMediator.o MessageMediatorColleague.o WrapInfo.o HandleMessage.o ClientEventObserver.o DrawCard.o DrawCardFactory.o GameEventObserver.o Player.o Plague.o Card.o EquipmentCard.o WeaponCard.o CardGenFactory.o Winchester.o Character.o CharacterGenFactory.o BartCassidy.o BlackJack.o

Socket.o: Socket.cpp
	g++ $(COBJECTFLAG) Socket.cpp
ListenSocket.o: ListenSocket.cpp
	g++ $(COBJECTFLAG) ListenSocket.cpp
HandleClientSocket.o: HandleClientSocket.cpp
	g++ $(COBJECTFLAG) HandleClientSocket.cpp

CommunicateFacade.o: CommunicateFacade.cpp
	g++ $(COBJECTFLAG) CommunicateFacade.cpp
Room.o: Room.cpp
	g++ $(COBJECTFLAG) Room.cpp
User.o: User.cpp
	g++ $(COBJECTFLAG) User.cpp

Player.o: Player.cpp
	g++ $(COBJECTFLAG) Player.cpp
Plague.o: Plague.cpp
	g++ $(COBJECTFLAG) Plague.cpp
Card.o: Card.cpp
	g++ $(COBJECTFLAG) Card.cpp
EquipmentCard.o: EquipmentCard.cpp
	g++ $(COBJECTFLAG) EquipmentCard.cpp
WeaponCard.o: WeaponCard.cpp
	g++ $(COBJECTFLAG) WeaponCard.cpp
CardGenFactory.o: CardGenFactory.cpp
	g++ $(COBJECTFLAG) CardGenFactory.cpp
Winchester.o: ./Card/Winchester.cpp
	g++ $(COBJECTFLAG) ./Card/Winchester.cpp

Character.o: Character.cpp
	g++ $(COBJECTFLAG) Character.cpp
CharacterGenFactory.o: CharacterGenFactory.cpp
	g++ $(COBJECTFLAG) CharacterGenFactory.cpp
BartCassidy.o: ./Character/BartCassidy.cpp
	g++ $(COBJECTFLAG) ./Character/BartCassidy.cpp
BlackJack.o: ./Character/BlackJack.cpp
	g++ $(COBJECTFLAG) ./Character/BlackJack.cpp

ClientEventObserver.o: ClientEventObserver.cpp
	g++ $(COBJECTFLAG) ClientEventObserver.cpp
GameEventObserver.o: GameEventObserver.cpp
	g++ $(COBJECTFLAG) GameEventObserver.cpp
Action.o: Action.cpp
	g++ $(COBJECTFLAG) Action.cpp
MessageMediator.o: MessageMediator.cpp
	g++ $(COBJECTFLAG) MessageMediator.cpp
MessageMediatorColleague.o: MessageMediatorColleague.cpp
	g++ $(COBJECTFLAG) MessageMediatorColleague.cpp
WrapInfo.o: WrapInfo.cpp
	g++ $(COBJECTFLAG) WrapInfo.cpp
	
Lounge.o: Lounge.cpp
	g++ $(COBJECTFLAG) Lounge.cpp
LoungeManage.o: LoungeManage.cpp
	g++ $(COBJECTFLAG) LoungeManage.cpp
HandleMessage.o: HandleMessage.cpp
	g++ $(COBJECTFLAG) HandleMessage.cpp
DrawCard.o: DrawCard.cpp
	g++ $(COBJECTFLAG) DrawCard.cpp
DrawCardFactory.o: DrawCardFactory.cpp
	g++ $(COBJECTFLAG) DrawCardFactory.cpp
