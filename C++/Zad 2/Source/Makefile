# Pawel Meller (241711)
# C++ course 2015, lab02

CC = g++

all: punkt.o odcinek.o trojkat.o main.o
	$(CC) punkt.o odcinek.o trojkat.o main.o -o main

main.o: main.cpp
	$(CC) main.cpp -c -o main.o

punkt.o: punkt.cpp
	$(CC) punkt.cpp -c -o punkt.o

odcinek.o: odcinek.cpp
	$(CC) odcinek.cpp -c -o odcinek.o

trojkat.o: trojkat.cpp
	$(CC) trojkat.cpp -c -o trojkat.o
