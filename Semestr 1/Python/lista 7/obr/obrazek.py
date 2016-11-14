# -*- encoding: utf8 -*-
from pygame_array import ArrayThread

N = 60            
A = ArrayThread(N)  # tworzenie wątku do rysowania kolorowej macierzy o wymiarze N*N
A.start()           # rozpoczącie działania tego wątku
obrazek = open("asd.txt")

for i in range(60):
  b = obrazek.next().split()
  for j in range(len(b)):
    d = str(b[j])
    c = d.replace("(","").replace(")","")
    c = c.split(",")
    A.put(i,j,(int(c[0]),int(c[1]),int(c[2])))
A.show()
