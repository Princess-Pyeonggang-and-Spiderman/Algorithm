import sys

sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

# dfs로 트리의 루트부터 리프까지 탐색하면서 depth 기록
def dfs(x, dep):
    depth[x] = dep
    for next in tree[x]:
        dfs(next, dep + 1)

t = int(input())

for _ in range(t):
    n = int(input())

    tree = [[] for _ in range(n + 1)]
    parent = [0] * (n + 1)
    depth = [0] * (n + 1)
    
    for _ in range(n - 1):
        a, b = map(int, input().split())
        tree[a].append(b)
        parent[b] = a

    # depth 기록
    for i in range(1, n + 1):
        if parent[i] == 0:
            dfs(i, 0)
            break

    a, b = map(int, input().split())

    # depth 부터 같도록 설정
    while depth[a] != depth[b]:
        if depth[a] > depth[b]:
            a = parent[a]
        else:
            b = parent[b]

    # depth가 같으면 같이 한 칸씩 위로 이동하며 찾기
    while a != b:
        a = parent[a]
        b = parent[b]
    
    print(a)