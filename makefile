CFLAGS= g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude
#All Targets
all: Run
	g++ -o bin/run bin/Card.o

Run:Card KeyGenerator

Card: bin/Card.o bin/FigureCard.o bin/NumericCard.o
bin/Card.o: src/Card.cpp
	$(CFLAGS) -o bin/Card.o  src/Card.cpp
bin/FigureCard.o: src/FigureCard.cpp
	$(CFLAGS) -o bin/FigureCard.o  src/FigureCard.cpp
bin/NumericCard.o: src/NumericCard.cpp
	$(CFLAGS) -o bin/NumericCard.o  src/NumericCard.cpp

KeyGenerator: bin/KeyGenerator.o
bin/KeyGenerator.o: src/KeyGenerator.cpp
	$(CFLAGS) -o bin/KeyGenerator.o  src/KeyGenerator.cpp

	
clean:
	rm -f bin/*
	