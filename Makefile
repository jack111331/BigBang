include Card.mk
include Character.mk

COBJECTFLAG = -Wall -g -c -Iinclude -I/usr/include/mysql -I/usr/local/include/mysql++ -lmysqlpp -o $@
CFLAG = -Wall -g -pthread -Iinclude -I/usr/include/mysql -I/usr/local/include/mysql++ -lmysqlpp

BuildList = Socket ListenSocket HandleClientSocket CommunicateFacade Action Room User Lounge LoungeManage MessageMediator MessageMediatorColleague WrapInfo HandleMessage ClientEventObserver DrawCard DrawCardFactory GameEventObserver Player Plague Card EquipmentCard CardGenFactory Character CharacterGenFactory Database ExclusiveCardInventory CardGenDecorator ExclusiveCardStore CharacterGenDecorator

BuildList := $(BuildList) $(CardBuildList) $(CharacterBuildList)

objectlist = $(foreach objectfile,$(BuildList),$(objectfile).o)

BangServer : $(objectlist) main.cpp
	g++ $(CFLAG) -o BangServer $(objectlist) main.cpp

%.o: %.cpp
	g++ $(COBJECTFLAG) $<
