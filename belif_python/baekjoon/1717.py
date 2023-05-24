import sys

sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]

def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    
    if a > b:
        parent[a] = parent[b]
    else:
        parent[b] = parent[a]

n, m = map(int, input().split())
parent = [i for i in range(n + 1)]

for _ in range(m):
    a, b, c = map(int, input().split())

    if a == 0:
        if find_parent(parent, b) != find_parent(parent, c):
            union_parent(parent, b, c)
    else:
        if find_parent(parent, b) == find_parent(parent, c):
            print("YES")
        else:
            print("NO")