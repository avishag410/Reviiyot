CC=g++

CFLAGS=-g -Wall -Weffc++ -std=c++11 -c -Iinclude

#All Targets
all: Reviiyot
Reviiyot: Main.o Card.o KeyGenerator.o FigureCard.o
	$(CC) Main.o Card.o KeyGenerator.o FigureCard.o -o Reviiyot

Main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Card.o: src/Card.cpp
	$(CC) $(CFLAGS) src/Card.cpp

FigureCard.o: src/FigureCard.cpp
	$(CC) $(CFLAGS) src/FigureCard.cpp

KeyGenerator.o: src/KeyGenerator.cpp
	$(CC) $(CFLAGS) src/KeyGenerator.cpp
clean:
	rm -f bin/*