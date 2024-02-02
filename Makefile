all: main

main: main.o
	g++ -o main main.o

main.o: main.cpp Entity.o TileElement.o Game.o
	g++ -c main.cpp Entity.o TileElement.o Game.o

Game.o: Game.cpp Entity.o TileElement.o
	g++ -c Game.cpp Entity.o TileElement.o

Entity.o: Entity.cpp
	g++ -c Entity.cpp

TileElement.o: TileElement.cpp
	g++ -c TileElement.cpp