
def maks(S):
    N = []
    M = {}
    for i in range(len(S)-3):
        for j in range(i+2,len(S)):
            try:
                A = eval(S[:i]+"("+S[i:j]+")"+S[j:])
                N.append(A)
                M[A] = (S[:i]+"("+S[:j]+")"+S[j:])
            except:
                pass
    return max(N), M[max(N)]

print maks("10+3*5-10+43*5")
print maks("1+1+1+1*2+2+2+2")
print maks("1+2-3+4-5+6-7+8-9+10")
