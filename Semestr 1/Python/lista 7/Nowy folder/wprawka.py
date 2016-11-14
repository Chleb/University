dobre = []
slowo = "a"
mak = "a"
naj = []
for i in open("slowa_cp1250.txt"):
    slowo = i.strip().lower()
    if len(slowo) == len(set(slowo)):
        dobre.append(slowo)
B = sorted(dobre)

for i in B:
    if len(i)>len(mak):
        naj = []
        naj.append(i)
        mak = i
    elif len(i) == len(mak):
        naj.append(i)

print " ".join(naj)
        
