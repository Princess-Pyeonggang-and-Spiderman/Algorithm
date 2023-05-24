import sys

input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]
    
def union_parent(parent, a, b):
    a, b = find_parent(parent, a), find_parent(parent, b)
    if a == b:
        noTrees.append(a)
        
    if a < b:
        parent[b] = parent[a]
    else:
        parent[a] = parent[b]

case = 0
while True:
    case += 1
    n, m = map(int, input().split())

    if n == 0 and m == 0:
        break
    
    parent = [i for i in range(n + 1)]
    noTrees = []
    
    for _ in range(m):
        a, b = map(int, input().split())
        union_parent(parent, a, b)
    
    noTrees_check = [False] * (n + 1)
    for noTree in noTrees:
        noTrees_check[find_parent(parent, noTree)] = True
        
    tree_parent = set()
    for i in range(1, n + 1):
        x = find_parent(parent, i)
        if not noTrees_check[x]:
            tree_parent.add(x)
            
    count = len(tree_parent)
            
    print("Case " + str(case) + ":", end=" ")
    if count == 0:
        print("No trees.")
    elif count == 1:
        print("There is one tree.")
    else:
        print("A forest of", count, "trees.")