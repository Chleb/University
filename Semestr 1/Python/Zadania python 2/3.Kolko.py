from math import sqrt
import sys

def kolko(n):
    a = [0.0,1.0]
    o = [n / 2.0,n / 2.0]
    if n % 2 == 1:
        v = n - 1
    else:
        v = n
    for j in range(v):
      z = 0
      while z == 0:
          if (n / 2.0) < (sqrt((o[0]-a[0])*(o[0]-a[0]) + (o[1]-a[1])*(o[1]-a[1]))) :
              sys.stdout.write(" ")
              a[0] = a[0] + 1
          else:
              z = 1
              print int(n - (2 * a[0])) * "#",
      print
      a[0] = 0
      a[1] = a[1] + 1

while 1 == 1:
  n = input()
  kolko(n)


