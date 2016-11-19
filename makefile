CFLAGS= g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude
#All Targets
all: hello
	g++ -o bin/run bin/try.o

hello:bin/try.o 

bin/try.o: src/try.cpp
	$(CFLAGS) -o bin/try.o src/try.cpp
	
clean:
	rm -f bin/*
	