all: main

main: main.cpp Entity.o TileElement.o Game.o
	g++ -o main Entity.o TileElement.o Game.o main.cpp 

Game.o: Game.cpp
	g++ -c Game.cpp

Entity.o: Entity.cpp
	g++ -c Entity.cpp

TileElement.o: TileElement.cpp
	g++ -c TileElement.cpp