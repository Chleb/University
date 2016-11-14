# Pawel Meller (241711)
# C++ course 2015, lab08

Flags = -Wall -Wundef -pedantic -pedantic-errors -std=c++11 -O3
CPP = g++

main: main.o
	$(CPP) $(Flags) main.o -o main

main.o: main.cpp computations.hpp
	$(CPP) $(Flags) main.cpp -c -o main.o

clean:
	rm main *.o
