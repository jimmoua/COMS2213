all: thing

thing: ddms.o IslandType.o MouseType.o Misc.o
	g++ ddms.o IslandType.o MouseType.o Misc.o -std=c++11 -o inputRead.out

ddms.o:
	g++ -c ./ddms.cpp -Wall

IslandType.o:
	g++ -c ./IslandType.cpp -Wall

MouseType.o:
	g++ -c ./MouseType.cpp -Wall

Misc.o:
	g++ -c ./Misc.cpp -Wall

rm:
	rm *.o *.out
