slowa = open("slowa_cp1250.txt")

def litery(n):
    c = {}
    a = list(n)
    for i in a:
        if i in c:
            c[i] += 1
        else:
            c[i] = 1
    return c
z = litery(str(raw_input()))
x = " "
while x != '':
    x = slowa.readline().strip()
    lista = litery(x)
    ukl = True
    for i in lista:
        if i in z:
            if lista[i] > z[i]:
                ukl = False
                break
        else:
            ukl = False
            break
    if ukl == True:
        print x

