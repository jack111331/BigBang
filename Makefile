BangServer : main.cpp Socket.o ListenSocket.o HandleClientSocket.o SocketIO.o 
	g++ -Wall -lpthread -o BangServer main.cpp Socket.o ListenSocket.o HandleClientSocket.o SocketIO.o
Socket.o: Socket.cpp
	g++ -Wall -c Socket.cpp
ListenSocket.o: ListenSocket.cpp
	g++ -Wall -c ListenSocket.cpp
HandleClientSocket.o: HandleClientSocket.cpp
	g++ -Wall -c HandleClientSocket.cpp
SocketIO.o: SocketIO.cpp
	g++ -Wall -c SocketIO.cpp
