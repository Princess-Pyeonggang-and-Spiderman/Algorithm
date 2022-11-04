import sys

sys.setrecursionlimit(10**6)
n = int(input())

graph = []

for _ in range(n):
    graph.append(list(map(int, input().split())))

results = []
def dfs(x, visited, result, count):
    if count == n+1 and x == 0:
        results.append(result)
    for i in range(n):
        if count != n and i == 0:
            continue
        if graph[x][i] == 0 or visited[i]:
            continue

        visited[i] = True
        dfs(i, visited, result + graph[x][i], count + 1)
        visited[i] = False

v = [False] * (n+1)
dfs(0, v, 0, 1)

print(min(results))