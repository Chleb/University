
class ListItem:
    def __init__(self,value):
        self.val = value
        self.next = None

def wypisz(lis):
    while lis!= None:
        print lis.val
        lis = lis.next

def ogon(lis):
    if lis != None:
        return lis.next
    else: return None

def wstawPocz(lis,nval):
    nowy = ListItem(nval)
    nowy.next = lis
    return nowy
  
def znajdz(lis,sval):
    while lis != None:
        if (lis.val == sval): return lis
        lis = lista.next
    return None

def usun(lis,uval):
    pom = lis
    while pom != None and pom.val != uval:
        poprz = pom
        pom = pom.next
    if pom != None:
        if pom == lis:
            lis = lis.next
        else:
            poprz.next = pom.next
    return lis

def wypiszPlus(lis):
    while lis != None:
        if lis.val >= 0:
            print lis.val
        lis = lis.next
         
def wstawKon(lis,nval):
    if lis == None:
        nowy = ListItem(nval)
        return nowy
    else:
        rest = wstawKon(lis.next,nval)
        lis.next = rest
        return lis

def usunkon(lis):
    kon = lis
    while kon.next != None:
        poprz = kon
        kon = kon.next
    poprz.next = kon.next
    return lis

def polacz(lis1,lis2):
    if lis1 == None:
        nowy = lis2
        return nowy
    else:
        rest = polacz(lis1.next,lis2)
        lis1.next = rest
        return lis1
    
def usunwsz(lis,uval):
    pom = lis
    while pom != None:
        if pom.val != uval:
            poprz = pom
            pom = pom.next
        else:
            if pom == lis:
                lis = lis.next
            else:
                poprz.next = pom.next
                poprz = pom
                pom = pom.next
    return lis

def zsipyw(lis):
    if lis.next == None:
        print lis.val
    else:
        zsipyw(lis.next)
        print lis.val

def odwr(lis):
    if lis.next == None:
        nowa = ListItem(lis.val)
        return nowa
    else:
        new = odwr(lis.next)
        wstawKon(new,lis.val)
    return new

def podziel(lis):
    plus = ListItem(0)
    minus = ListItem(0)
    while lis != None:
        if lis.val < 0:
            minus = wstawKon(minus,lis.val)
        else:
            plus = wstawKon(plus,lis.val)
        lis = lis.next
    plus = ogon(plus)
    minus = ogon(minus)
    return plus,minus

lis = ListItem(35)
lis = wstawKon(lis,-2)
lis = wstawKon(lis,10)
lis = wstawKon(lis,-15)
lis = wstawKon(lis,2)
mis = ListItem(-50)
mis = wstawKon(mis,51)
mis = wstawKon(mis,2)
lis = polacz(lis,mis)
lis,mis = podziel(lis)
wypisz(lis)
print"----"
wypisz(mis)

input()
