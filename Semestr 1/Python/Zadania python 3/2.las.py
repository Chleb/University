from turtle import *
from random import randint
speed('fastest')

def drzewko(x,maxit,spr):
    skonczone = "false"
    lasttrn = {}
    A = [0] * maxit
    B = [0]
    lt(90)
    fd(x)
    x = 0.8 * x
    currit = 0
    while currit >= 0:
        if len(B) > maxit:
            B[maxit + 1:len(B)] = []
        ang = randint(30 - (10 * spr),30 + (10 * spr))
        if B[currit] == 0 and  currit < maxit:
            A[currit] = ang
            lt(ang)
            lasttrn[currit] = "left"
            fd(x)
            x = 0.8 * x
            currit += 1
            B.append(0)
        elif B[currit] == 1:
            A[currit] = ang
            rt(ang)
            lasttrn[currit] = "right"
            for i in reversed(range((currit + 1),maxit)):
               B[i] = 0
            fd(x)
            x = 0.8 * x
            currit += 1
            B.append(0)
        elif currit == maxit:
            x = x / 0.8
            bk(x)
            currit -= 1
            B[currit] += 1
            if lasttrn[currit] == "left":
                rt(A[currit])
            elif lasttrn[currit] == "right":
                lt(A[currit])
        elif B[currit] == 2:
            x = x / 0.8
            bk(x)
            currit -= 1
            if currit > - 1:
                B[currit] += 1
                if lasttrn[currit] == "left":
                    rt(A[currit])
                else:
                    lt(A[currit])
            else:
                pass
    A = []
    B = []
up()
lt(45)
bk(300)
rt(45)
down()
drzewko(40,4,2)
up()
rt(90)
fd(200)
down()
drzewko(60,7,3)
up()
rt(90)
fd(200)
down()
drzewko(50,5,1)               

input()
