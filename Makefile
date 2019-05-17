COBJECTFLAG = -Wall -c -Iinclude
CFLAG = -Wall -pthread -Iinclude

BuildList = Socket ListenSocket HandleClientSocket CommunicateFacade Action Room User Lounge LoungeManage MessageMediator MessageMediatorColleague WrapInfo HandleMessage ClientEventObserver DrawCard DrawCardFactory GameEventObserver Player Plague Card EquipmentCard CardGenFactory Winchester Mustang Volcanic Character CharacterGenFactory BartCassidy BlackJack

objectlist = $(foreach objectfile,$(BuildList),$(objectfile).o)

.PHONY : gen

BangServer : $(objectlist) main.cpp
	g++ $(CFLAG) -o BangServer $(objectlist) main.cpp

%.o: %.cpp
	g++ $(COBJECTFLAG) $<
	
Winchester.o: ./Card/Winchester.cpp
	g++ $(COBJECTFLAG) $<

Mustang.o: ./Card/Mustang.cpp
	g++ $(COBJECTFLAG) $<
	
Volcanic.o: ./Card/Volcanic.cpp
	g++ $(COBJECTFLAG) $<

BlackJack.o: ./Character/BlackJack.cpp
	g++ $(COBJECTFLAG) $<
	
BartCassidy.o: ./Character/BartCassidy.cpp
	g++ $(COBJECTFLAG) $<
