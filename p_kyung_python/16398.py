import sys
input = sys.stdin.readline
n = int(input())
flow = [[0] * n for _ in range(n)]
costs = []
result = 0

def find_parent(x):
    if parent[x] != x:
        parent[x] = find_parent(parent[x])
    return parent[x]

def union_parent(a, b):
    a = find_parent(a)
    b = find_parent(b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

for i in range(n):
    flow[i] = list(map(int, input().split()))

for i in range(n-1):
    for j in range(i+1, n):
        costs.append([flow[i][j], i, j])
costs.sort()
parent = [i for i in range(n)]
for cost in costs:
    c, a, b = cost
    if find_parent(a) != find_parent(b):
        union_parent(a, b)
        result += c

print(result)
