slowa = open("slowa_cp1250.txt")
word = {}
rev = []
x = " "
while x != '':
    x = slowa.readline().strip()
    word[x] = True
    
podane = ["kotka","kula","kutwa","lin","matura","para","pranie","ropa","setka","sowa"]

for i in range(len(podane)):
    for j in range(len(podane)):
        if i != j:
            b = list(podane[j])
            for k in range(1,len(b) - 1):
                c = b[:]
                c.insert(k,podane[i])
                slowo = "".join(c)
                if slowo in word:
                    print slowo
