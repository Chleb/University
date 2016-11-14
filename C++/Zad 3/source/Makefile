CC = g++

all: stos.o main.o
	$(CC) -std=c++11 stos.o main.o -o main

main.o: main.cpp
	$(CC) -std=c++11 main.cpp -c -o main.o

stos.o: stos.cpp
	$(CC) -std=c++11 stos.cpp -c -o stos.o

clean:
	rm -f *.o main
