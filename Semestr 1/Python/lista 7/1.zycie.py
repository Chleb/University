first = """
......#.......
.....#........
....#.........
...#..........
..#.......#...
.#........#...
#.........#...
"""

adj = [[-1,1],[0,1],[1,1],[-1,0],[1,0],[-1,-1],[0,-1],[1,-1]]   #wspolrzedne sasiadow

    
def zap(a):                             #zapetlenie wspolrzednych
    b = a[:]
    if b[0] == -1:
        b[0] = len(old_plane) - 1
    elif b[0] == len(old_plane):
        b[0] = 0
    if b[1] == -1:
        b[1] = len(old_plane[0]) - 1
    elif b[1] == len(old_plane[0]):
        b[1] = 0
    return b
    
def prt(b):             #wypisywanie stanu planszy
    a = ""
    for i in b:
        for j in i:
            if j == ".":
                a = a + "."
            else:
                a = a + "#"
        a = a + "\n"
    print a

def krok(c):
    new_plane = [c[i][:] for i in range(len(c))]
    for i in range(len(c)):
        for j in range(len(c[i])):
            ls = 0             #liczba sasiadow
            for k in adj:
                a = zap([i + k[0],j + k[1]])
                if c[a[0]][a[1]] == "#":
                    ls += 1
            if c[i][j] == "#":
                if ls <= 1 or ls >=4:
                    new_plane[i][j] = "."
                elif ls == 2 or ls == 3:
                    new_plane[i][j] = "#"
            elif c[i][j] == "." and ls == 3:
                new_plane[i][j] = "#"
            else:
                new_plane[i][j] = "."
    return new_plane                   

old_plane = first.split()
for i in range(len(old_plane)):
    old_plane[i] = list(old_plane[i])

PL = []
se = 0
while True:
    prt(old_plane)
    PL.append(old_plane)
    old_plane = krok(old_plane)
    adult = False
    for i in range(len(PL) - 1):
        if old_plane == PL[i]:
            adult = True
            g = i
            break
    if adult == True:
        print "Etap poszukiwan:",se," krokow"
        print "Etap stabilizacji:", se - g, " krokow"
    se += 1
    raw_input()

















