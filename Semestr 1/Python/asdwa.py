import itertools


def plmin(S,N):
  if N == 0:
    return [ [] ]
  return [ [x] + r for x in S for r in plmin(S,N-1)]

def nmerge(L,N):
    m = []
    for i in range(len(N)):
        m.append(L[i])
        m.append(N[i])
        a = i
    m += L[(i + 1):]
    return m

def zero(L):
    B = map(str,L)
    m = plmin("+-",len(L)-1)
    for i in m:
        A = "".join(nmerge(B,i))
        if eval(A) == 0:
            return A
    return "Nie mozliwe"

L = [1]+[2**i for i in range(11)]

print zero(L)
