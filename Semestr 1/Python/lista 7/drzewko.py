from turtle import *
from math import *
speed("fastest")
def pap(D,a,b):
    if D < 2:
        return
    else:
        pencolor(sin(a) * sin(a),cos(a) * cos(a),sin(2 * a) * sin(2 * a))
        fd(D)
        lt(90)
        pap(0.5 * D,a * +1.4,0)
        rt(95 - (b * 10))
        pap(0.8 * D,a * +1.1,0)
        rt(80)
        pap(0.5 * D,a * +1.9,1)
        lt(85 - (b * 10))
        fd(-D)

               
pap(50,1,0)
