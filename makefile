CC=g++

CFLAGS=-g -Wall -Weffc++ -std=c++11 -c -Iinclude

#All Targets
all: Reviiyot
Reviiyot: bin/reviiyot.o bin/Card.o bin/KeyGenerator.o bin/FigureCard.o bin/NumericCard.o bin/Deck.o bin/Utils.o bin/Hand.o bin/Player.o bin/PlayerType1.o bin/GameManager.o bin/Game.o
	$(CC) bin/reviiyot.o bin/Card.o bin/KeyGenerator.o bin/FigureCard.o bin/NumericCard.o bin/Deck.o bin/Utils.o bin/Hand.o bin/Player.o bin/PlayerType1.o bin/GameManager.o bin/Game.o -o bin/reviiot

bin/reviiyot.o: src/reviiyot.cpp
	$(CC) $(CFLAGS) -o bin/reviiyot.o src/reviiyot.cpp

bin/Card.o: src/Card.cpp
	$(CC) $(CFLAGS) -o bin/Card.o src/Card.cpp

bin/FigureCard.o: src/FigureCard.cpp
	$(CC) $(CFLAGS) -o bin/FigureCard.o src/FigureCard.cpp
bin/NumericCard.o: src/NumericCard.cpp
	$(CC) $(CFLAGS) -o bin/NumericCard.o src/NumericCard.cpp

bin/KeyGenerator.o: src/KeyGenerator.cpp
	$(CC) $(CFLAGS) -o bin/KeyGenerator.o src/KeyGenerator.cpp
bin/Deck.o: src/Deck.cpp
	$(CC) $(CFLAGS) -o bin/Deck.o src/Deck.cpp
bin/Utils.o: src/Utils.cpp
	$(CC) $(CFLAGS) -o bin/Utils.o src/Utils.cpp
bin/Player.o: src/Player.cpp
	$(CC) $(CFLAGS) -o bin/Player.o src/Player.cpp
bin/PlayerType1.o: src/PlayerType1.cpp
	$(CC) $(CFLAGS) -o bin/PlayerType1.o src/PlayerType1.cpp
bin/Hand.o: src/Hand.cpp
	$(CC) $(CFLAGS) -o bin/Hand.o src/Hand.cpp
bin/GameManager.o: src/GameManager.cpp
	$(CC) $(CFLAGS) -o bin/GameManager.o src/GameManager.cpp
bin/Game.o: src/Game.cpp
	$(CC) $(CFLAGS) -o bin/Game.o src/Game.cpp
clean:
	rm -rf bin/*.o bin/reviiot