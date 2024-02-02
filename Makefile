CFLAGS = -g -Wall -Wextra -pedantic -fsanitize=address

all: main

main: main.cpp Entity.o TileElement.o keyboard.o beginning.o Game.o
	g++ -o main Entity.o TileElement.o keyboard.o beginning.o Game.o main.cpp $(CFLAGS)

Game.o: Game.cpp
	g++ -c Game.cpp $(CFLAGS)

Entity.o: Entity.cpp
	g++ -c Entity.cpp $(CFLAGS)

TileElement.o: TileElement.cpp
	g++ -c TileElement.cpp $(CFLAGS)

keyboard.o: keyboard.cpp
	g++ -c keyboard.cpp $(CFLAGS)

beginning.o: beginning.cpp
	g++ -c beginning.cpp

