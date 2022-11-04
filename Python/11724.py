import sys

# 재귀 제한 늘리기
sys.setrecursionlimit(10000)
# 입력 시간 줄이기
input = sys.stdin.readline

# n, m 입력
n, m = map(int, input().split())

# 간선을 저장할 graph, 방문 여부를 기록할 visited
graph = [[] for _ in range(n+1)]
visited = [False] * (n+1)

# 간선 입력
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

# 간단한 dfs
def dfs(x):
    visited[x] = True
    for y in graph[x]:
        if not visited[y]:
            dfs(y)

# 1 ~ n 까지 방문하지 않은 곳이 있다면 dfs
result = 0
for i in range(1, n+1):
    if not visited[i]:
        result += 1
        dfs(i)

print(result)