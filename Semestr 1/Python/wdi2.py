

class TreeItem:
    def __init__(self,value):
        self.val = value
        self.left = None
        self.right = None

def insert( root, nkey):
    if (root == None):
        return TreeItem(nkey)
    if (nkey < root.val):
        root.left = insert(root.left, nkey)
    else:
        if (nkey > root.val):
            root.right = insert(root.right, nkey)
    return root

def write(root):
    if (root !=None):
        write(root.left)
        if root.val >= 0:
            print root.val
        write(root.right)

def ile(root):
    if root == None:
        return 0
    else:
        return 1 + ile(root.left) + ile(root.right)

def wys(root):
    if root == None:
        return 0
    else:
        w1 = wys(root.left)
        w2 = wys(root.right)
        if w1 > w2:
            return (w1 + 1)
        else:
            return (w2 + 1)

def polacz(root1,root2):
    cur = root2
    while cur.left != None:
        prev = cur
        cur = cur.left
    L = TreeItem(cur.val)
    prev.left = cur.right
    L.left = root1
    L.right = root2
    return L



L = TreeItem(4)
insert(L,2);insert(L,1);insert(L,3);insert(L,6);insert(L,5);insert(L,7)
B = TreeItem(15)
insert(B,13);insert(B,12);insert(B,14);insert(B,17);insert(B,16);insert(B,18)

C = polacz(L,B)
write(C)
