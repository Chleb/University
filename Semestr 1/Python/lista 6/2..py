slowa = open("slowa_cp1250.txt")
word = {}
rev = []
x = " "
while x != '':
    x = slowa.readline().strip()
    word[x] = True
    if x[::-1] in word:
        print x," ",x[::-1]
        rev.append(x)
    
