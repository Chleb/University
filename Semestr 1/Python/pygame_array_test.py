# -*- encoding: utf8 -*-
from pygame_array import ArrayThread

N = 60            
A = ArrayThread(N)  # tworzenie wątku do rysowania kolorowej macierzy o wymiarze N*N
A.start()           # rozpoczącie działania tego wątku

for j in range(2000):
  A.clear()         # cała macierz zawiera białe kolory   
  for i in range(N):
     x = (i + j) % N
     y = (i + 2*j) % N
     A.put(x,y,(50,100,200))  # umieszczenie jakiegoś koloru w punkcie x,y
     A.put(y,x,(255,200,(i+j) % 255))
  A.show()        # wizualizacja ostatnio wykonanych "putów"
  A.tick()        # trochę odciąża procesor na bardzo szybkich komputerach

A.join()          
