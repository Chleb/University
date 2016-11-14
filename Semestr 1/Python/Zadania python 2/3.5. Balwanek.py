from math import sqrt
from math import fabs
import sys

def kolko(b,n):
    a = [0.0,1.0]
    o = [n / 2.0,n / 2.0]
    for j in range(n - 1):
      z = 0
      print b * " ",
      while z == 0:
          if (n / 2.0) <= (sqrt((o[0]-a[0])*(o[0]-a[0]) + (o[1]-a[1])*(o[1]-a[1]))) :
              sys.stdout.write(" ")
              a[0] = a[0] + 1
          else:
              z = 1
              print int(n - (2 * a[0])) * "#",
      print
      a[0] = 0
      a[1] = a[1] + 1
x = input()
kolko(6*x,5*x)
kolko(5*x,7*x)
kolko(3*x,11*x)

input()
