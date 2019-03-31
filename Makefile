BangServer : main.cpp Socket.o ListenSocket.o HandleClientSocket.o SocketIO.o Player.o Plague.o Card.o EquipmentCard.o WeaponCard.o Winchester.o Character.o
	g++ -Wall -lpthread -o BangServer main.cpp Socket.o ListenSocket.o HandleClientSocket.o SocketIO.o
	
	
Socket.o: Socket.cpp
	g++ -Wall -c Socket.cpp
ListenSocket.o: ListenSocket.cpp
	g++ -Wall -c ListenSocket.cpp
HandleClientSocket.o: HandleClientSocket.cpp
	g++ -Wall -c HandleClientSocket.cpp
SocketIO.o: SocketIO.cpp
	g++ -Wall -c SocketIO.cpp

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
