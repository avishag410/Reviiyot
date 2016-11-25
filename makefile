CC=g++

CFLAGS=-g -Wall -Werror -Weffc++ -std=c++11 -c -Iinclude

#All Targets
all: Reviiyot
Reviiyot: Main.o Card.o KeyGenerator.o FigureCard.o NumericCard.o Deck.o Utils.o Hand.o Player.o PlayerType1.o GameManager.o Game.o
	$(CC) Main.o Card.o KeyGenerator.o FigureCard.o NumericCard.o Deck.o Utils.o Hand.o Player.o PlayerType1.o GameManager.o Game.o -o Reviiyot

Main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Card.o: src/Card.cpp
	$(CC) $(CFLAGS) src/Card.cpp

FigureCard.o: src/FigureCard.cpp
	$(CC) $(CFLAGS) src/FigureCard.cpp
NumericCard.o: src/NumericCard.cpp
	$(CC) $(CFLAGS) src/NumericCard.cpp

KeyGenerator.o: src/KeyGenerator.cpp
	$(CC) $(CFLAGS) src/KeyGenerator.cpp
Deck.o: src/Deck.cpp
	$(CC) $(CFLAGS) src/Deck.cpp
Utils.o: src/Utils.cpp
	$(CC) $(CFLAGS) src/Utils.cpp
Player.o: src/Player.cpp
	$(CC) $(CFLAGS) src/Player.cpp
PlayerType1.o: src/PlayerType1.cpp
	$(CC) $(CFLAGS) src/PlayerType1.cpp
Hand.o: src/Hand.cpp
	$(CC) $(CFLAGS) src/Hand.cpp
GameManager.o: src/GameManager.cpp
	$(CC) $(CFLAGS) src/GameManager.cpp
Game.o: src/Game.cpp
	$(CC) $(CFLAGS) src/Game.cpp
clean:
	rm -rf *.o Reviiyot