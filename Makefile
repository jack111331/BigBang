COBJECTFLAG = -Wall -c -Iinclude -I/usr/include/mysql -I/usr/local/include/mysql++ -lmysqlpp
CFLAG = -Wall -pthread -Iinclude -I/usr/include/mysql -I/usr/local/include/mysql++ -lmysqlpp

BuildList = Socket ListenSocket HandleClientSocket CommunicateFacade Action Room User Lounge LoungeManage MessageMediator MessageMediatorColleague WrapInfo HandleMessage ClientEventObserver DrawCard DrawCardFactory GameEventObserver Player Plague Card EquipmentCard CardGenFactory Winchester Mustang Volcanic Schofield Remington Carabine Barrel Jail Stagecoach Wellsfargo Saloon Bang Missed Gatling Indians Duel Beer Character CharacterGenFactory BartCassidy BlackJack ElGringo VultureSam SuzyLafayette RoseDoolan PaulRegret WillyTheKid

objectlist = $(foreach objectfile,$(BuildList),$(objectfile).o)

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
	
Carabine.o: ./Card/Carabine.cpp
	g++ $(COBJECTFLAG) $<

Remington.o: ./Card/Remington.cpp
	g++ $(COBJECTFLAG) $<
	
Schofield.o: ./Card/Schofield.cpp
	g++ $(COBJECTFLAG) $<
	
Barrel.o: ./Card/Barrel.cpp
	g++ $(COBJECTFLAG) $<

Jail.o: ./Card/Jail.cpp
	g++ $(COBJECTFLAG) $<
	
Wellsfargo.o: ./Card/Wellsfargo.cpp
	g++ $(COBJECTFLAG) $<

Stagecoach.o: ./Card/Stagecoach.cpp
	g++ $(COBJECTFLAG) $<
	
Saloon.o: ./Card/Saloon.cpp
	g++ $(COBJECTFLAG) $<
	
Bang.o: ./Card/Bang.cpp
	g++ $(COBJECTFLAG) $<
	
Missed.o: ./Card/Missed.cpp
	g++ $(COBJECTFLAG) $<

Gatling.o: ./Card/Gatling.cpp
	g++ $(COBJECTFLAG) $<

Indians.o: ./Card/Indians.cpp
	g++ $(COBJECTFLAG) $<
	
Duel.o : ./Card/Duel.cpp
	g++ $(COBJECTFLAG) $<

Beer.o : ./Card/Beer.cpp
	g++ $(COBJECTFLAG) $<
	
BlackJack.o: ./Character/BlackJack.cpp
	g++ $(COBJECTFLAG) $<
	
BartCassidy.o: ./Character/BartCassidy.cpp
	g++ $(COBJECTFLAG) $<
	
ElGringo.o: ./Character/ElGringo.cpp
	g++ $(COBJECTFLAG) $<

VultureSam.o: ./Character/VultureSam.cpp
	g++ $(COBJECTFLAG) $<
	
SuzyLafayette.o: ./Character/SuzyLafayette.cpp
	g++ $(COBJECTFLAG) $<

RoseDoolan.o: ./Character/RoseDoolan.cpp
	g++ $(COBJECTFLAG) $<
	
PaulRegret.o: ./Character/PaulRegret.cpp
	g++ $(COBJECTFLAG) $<

WillyTheKid.o: ./Character/WillyTheKid.cpp
	g++ $(COBJECTFLAG) $<
