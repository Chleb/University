from math import sqrt
B = [(n*n)-1 for n in range(2,3000)]
A =[2,3]
C = {2:1,3:1}
x = 3
while x < 9000000:
    x += 2
    p = "True"
    for i in A:
            if i > sqrt(x):
                break
            if x % i == 0:
                p = "False"
                break
    if p == "True":
        A.append(x)
        C[x] = 1
for j in B:
    if j in C:
     print j
print "kupa"
