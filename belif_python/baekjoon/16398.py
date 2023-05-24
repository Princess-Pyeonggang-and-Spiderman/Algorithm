def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])

    return parent[x]

def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)

    if a < b:
        parent[b] = parent[a]
    else:
        parent[a] = parent[b]


n = int(input())

# edge = [(비용, 시작 노드, 도착 노드)]
# parent 부모 노드 ex) parent[1] -> 노드 1의 부모노드
edges = []
parent = [i for i in range(n + 1)]

for i in range(n):
    tmp = list(map(int, input().split()))
    for j in range(n):
        if i == j:
            continue
        edges.append((tmp[j], i, j))

edges.sort()

result = 0
for edge in edges:
    cost, a, b = edge
    if find_parent(parent, a) != find_parent(parent, b):
        union_parent(parent, a, b)
        result += cost

print(result)
