from duze_cyfry import dajCyfre
x = input()
for i in range(5):
    for j in range(len(str(x))):
        c = dajCyfre(int(list(str(x))[j]))
        print c[i]," ",
    print
input()
