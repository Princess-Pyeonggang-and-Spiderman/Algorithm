import sys

def find_parent(parent, x):
    if x != parent[x]:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]

def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)

    if a < b:
        parent[b] = parent[a]
    else:
        parent[a] = parent[b]

input = sys.stdin.readline
n, m = map(int, input().split())

space = []
edges = []
# 0 ~ n + 1 까지 초기화 ([0, 1, 2, ... ,n - 1, n])
parent = [i for i in range(n + 1)]

# 우주신들의 좌표 입력
for _ in range(n):
    space.append(list(map(int, input().split())))

# 이미 연결되어 있는 통로 입력 받은 후 union
for _ in range(m):
    a, b = map(int, input().split())
    if find_parent(parent, a) != find_parent(parent, b):
        union_parent(parent, a, b)

# 모든 좌표를 돌면서 모든 통로들을 확인하여 edges에 append
for i in range(1, n + 1):
    for j in range(1, n + 1):
        if i == j :
            continue
        
        x1, y1, x2, y2 = space[i - 1][0], space[i - 1][1], space[j - 1][0], space[j - 1][1]
        edges.append((((x2 - x1) ** 2 + (y2 - y1) ** 2) ** 0.5, i, j))

# 크루스칼 (값이 작은 통로부터 연결)
edges.sort()

result = 0
for edge in edges:
    cost, a, b = edge
    if find_parent(parent, a) != find_parent(parent, b):
        union_parent(parent, a, b)
        result += cost

# 소수 둘째자리까지 출력
print("{:.2f}".format(result))