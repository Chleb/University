
def czypos(L):
    return True if len(L)==2 and a[0]<=a[1] else all((czypos(L[x],L[x + 1]) for x in range(L - 1)))

print czypos([1,2,3,4,5])
