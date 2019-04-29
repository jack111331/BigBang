BangServer : main.cpp Socket.o ListenSocket.o HandleClientSocket.o SocketFacade.o Action.o Room.o User.o Lounge.o LoungeManage.o ClientEventObserver.o GameEventObserver.o Player.o Plague.o Card.o EquipmentCard.o WeaponCard.o Winchester.o Character.o BartCassidy.o BlackJack.o
	g++ -Wall -lpthread -o BangServer main.cpp Socket.o ListenSocket.o HandleClientSocket.o SocketFacade.o Action.o Room.o User.o Lounge.o LoungeManage.o ClientEventObserver.o  GameEventObserver.o Player.o Plague.o Card.o EquipmentCard.o WeaponCard.o Winchester.o Character.o BartCassidy.o BlackJack.o
	rm *.o


Socket.o: Socket.cpp
	g++ -Wall -c Socket.cpp
ListenSocket.o: ListenSocket.cpp
	g++ -Wall -c ListenSocket.cpp
HandleClientSocket.o: HandleClientSocket.cpp
	g++ -Wall -c HandleClientSocket.cpp

SocketFacade.o: SocketFacade.cpp
	g++ -Wall -c SocketFacade.cpp
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
	
Lounge.o: Lounge.cpp
	g++ -Wall -c Lounge.cpp
LoungeManage.o: LoungeManage.cpp
	g++ -Wall -c LoungeManage.cpp
