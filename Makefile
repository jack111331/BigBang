BangServer : main.cpp Socket.o ListenSocket.o HandleClientSocket.o 
	g++ -Wall -o BangServer main.cpp Socket.o ListenSocket.o HandleClientSocket.o
Socket.o: Socket.cpp
	g++ -Wall -c Socket.cpp
ListenSocket.o: ListenSocket.cpp
	g++ -Wall -c ListenSocket.cpp
HandleClientSocket.o: HandleClientSocket.cpp
	g++ -Wall -c HandleClientSocket.cpp
