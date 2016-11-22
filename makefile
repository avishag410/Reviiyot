CC=g++

CFLAGS=-g -Wall -Weffc++ -std=c++11 -c -Iinclude

#All Targets
all: Reviiyot
Reviiyot: Main.o Card.o KeyGenerator.o FigureCard.o NumericCard.o Deck.o Utils.o
	$(CC) Main.o Card.o KeyGenerator.o FigureCard.o NumericCard.o Deck.o Utils.o -o Reviiyot

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

clean:
	rm -rf *.o Reviiyot