from spelnial import *

def tau(S):
    return not sat("-(" + S + ")")
print tau("n + -n")
