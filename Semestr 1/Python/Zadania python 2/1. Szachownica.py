a = input()
b = input()
def szachwica(a):
  c = 0
  for k in range(a * 2):
    for j in range(b):
      if (k % 2) == 0:
          print "",
          for  i in range(a):
              print(b - 2) * " ",b * "#",
          print
      else:
          for  i in range(a):
              print b * "#",(b - 2) * " ",
          print
szachwica(a)
input()
