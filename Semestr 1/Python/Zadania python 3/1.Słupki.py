from turtle import *
from random import randint
speed('fastest')
def slupek(b):
    fd(10)
    lt(90)
    fd(b)
    lt(90)
    fd(10)
    lt(90)
    fd(b)
    lt(90)
    up()
    fd(15)
    down()
up()
lt(45)
bk(300)
rt(45)
down()
for i in range(30):
    x = randint(20,300)
    slupek(x)
input()
