# Czy formula jest spelnialna?
# Trochê inaczej ni¿ na wykladzie, ale mo¿e zwiezlej

letters = set("abcdefghijklmnopqrstuvxyz")

def seqs(S,N):
  if N == 0:
    return [ [] ]
  return [ [x] + r for x in S for r in seqs(S,N-1)]

def sat(F):
  variables = set(F) & letters
  F = F.replace("+", " or ").replace("*", " and ").replace("-", " not ").replace("A", "True").replace("B", "False")
  valuations = [ dict( zip(variables,s)) for s in seqs([False, True], len(variables))]
  return any([ eval(F,v) for v in valuations])

if __name__ == "__main__":
  # Dzieki poprzedniemu wierszowi, ten kod NIE wykona sie, gdy bedziemy importowac modul
  print ("Wszystkie ciagi" + str(seqs("ab",2)))
  print ("2 ** 10 == " + str(len(seqs("ab",10))))
  print (sat("a + b * (c + -a)"))
