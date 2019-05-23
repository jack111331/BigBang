include Card.mk
include Character.mk

COBJECTFLAG = -Wall -c -Iinclude -I/usr/include/mysql -I/usr/local/include/mysql++ -lmysqlpp -o $@
CFLAG = -Wall -pthread -Iinclude -I/usr/include/mysql -I/usr/local/include/mysql++ -lmysqlpp

BuildList = Socket ListenSocket HandleClientSocket CommunicateFacade Action Room User Lounge LoungeManage MessageMediator MessageMediatorColleague WrapInfo HandleMessage ClientEventObserver DrawCard DrawCardFactory GameEventObserver Player Plague Card EquipmentCard CardGenFactory Character CharacterGenFactory

BuildList := $(BuildList) $(CardBuildList) $(CharacterBuildList)

objectlist = $(foreach objectfile,$(BuildList),$(objectfile).o)

BangServer : $(objectlist) main.cpp
	g++ $(CFLAG) -o BangServer $(objectlist) main.cpp

%.o: %.cpp
	g++ $(COBJECTFLAG) $<
