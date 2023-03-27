import sys

sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

def dfs(x):
    # 음수로 return이 되면 양이 지금까지 없었는데 늑대의 수만큼 빼게 되므로 max(0) 적용
    for next_node in tree[x]:
        islands[x] += max(dfs(next_node), 0)

    return islands[x]

n = int(input())

# 트리와 섬의 정보(늑대 : 음수, 양 : 양수)
tree = [[] for _ in range(n + 1)]
islands = [0] * (n + 1)

for i in range(2, n + 1):
    t, a, p = map(str, input().split())

    islands[i] = int(a) if t == "S" else -int(a)
    tree[int(p)].append(i)

# 트리 탐색
print(dfs(1))