slowa = open("slowa_cp1250.txt")
x = slowa.readline().strip()

def litery(n):
    c = {}
    a = list(n)
    for i in a:
        if i in c:
            c[i] += 1
        else:
            c[i] = 1
    return c

art = "".join(raw_input().split()).lower()
di = litery(art)
x = " "
while x != '':
    x = slowa.readline().strip()
    lista = litery(x)
    ukl = True
    for i in lista:
        if i in di:
            if lista[i] > di[i]:
                ukl = False
        else:
            ukl = False
    if ukl == True:
        print x
        z = " "
        while z != '':
            z = slowa.readline().strip()
            listb = litery(z)
            for i in listb:
                if i in di and not i in lista:
                    if listb[i] != di[i]:
                        ukl = False
                elif i in di and i in lista:
                    if listb[i] != di[i] - lista[i]:
                        ukl = False
                else:
                    ukl = False
            if ukl == True:
                print z
        slowa.seek(0)
