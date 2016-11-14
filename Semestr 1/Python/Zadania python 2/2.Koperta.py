import sys

while 1 == 1:
 x = input()
 def a():
  sys.stdout.write("*")
 def b():
  sys.stdout.write(" ")
 print x * "*"
 for i in range(((x-2)/2)-1):
     a()
     for j in range(i):
       if i > 0:
          b()
     a()
     for j in range((x-4)-(2 * i)):
          b()
     a()
     for j in range(i):
      if i > 0:
       b()
     a()
     print
 if (x % 2) == 0:
    print "*",((x/2)-4) * " ","**",((x/2)-4) * " ","*"
 else:
    print "*",((x/2)-4) * " ","* *",((x/2)-4) * " ","*"
    print "*",((x/2)-3) * " ","*",((x/2)-3) * " ","*"
    print "*",((x/2)-4) * " ","* *",((x/2)-4) * " ","*"
 for i in reversed(range(((x-2)/2)-1)):
     a()
     for j in range(i):
       if i > 0:
          b()
     a()
     for j in range((x-4)-(2 * i)):
          b()
     a()
     for j in range(i):
      if i > 0:
       b()
     a()
     print
 print x * "*"

