def dfs(x, y):
    global r, c, result

    if y == c - 1:
        result += 1
        return True

    for i in range(3):
        nx = x + dx[i]
        ny = y + dy[i]

        if nx < 0 or nx >= r or ny >= c:
            continue
        if graph[nx][ny] == "x" or visited[nx][ny]:
            continue

        visited[nx][ny] = True
        if dfs(nx, ny):
            return True

    return False

r, c = map(int, input().split())
graph = [list(str(input())) for _ in range(r)]
visited = [[False] * c for _ in range(r)]

dx = [-1, 0, 1]
dy = [1, 1, 1]

result = 0

for i in range(r):
    visited[i][0] = True
    dfs(i, 0)

print(result)