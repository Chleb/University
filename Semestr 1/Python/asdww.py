from turtle import *
speed("fastest")
def rys(dl,il,st,gl):
    if gl == 0:
        return
    else:
        for i in range(il):
            rys(dl * (0.01 * st),il,st,gl-1)
            fd(dl)
            lt(360 / il)


rys(100,6,33.33,3)
