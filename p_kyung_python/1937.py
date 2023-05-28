import sys

sys.setrecursionlimit(10 ** 6)

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

n = int(input())
bamboo = []


def dfs(x, y):
    if visited[x][y]: return visited[x][y]
    visited[x][y] = 1
    for i in range(4):
        nx, ny = dx[i] + x, dy[i] + y
        if nx < 0 or nx >= n or ny < 0 or ny >= n:
            continue
        if bamboo[nx][ny] > bamboo[x][y]:
            visited[x][y] = max(visited[x][y], dfs(nx, ny) + 1)
    return visited[x][y]


for i in range(n):
    bamboo.append(list(map(int, input().split())))

result = 0
visited = [[0] * n for _ in range(n)]

for i in range(n):
    for j in range(n):
        result = max(result, dfs(i, j))
print(result)