import sys

sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline
n = int(input())

forest = [list(map(int, input().split())) for _ in range(n)]
dp = [[1] * n for _ in range(n)]

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

def dfs(x, y):
    # 이미 dp에 기록이 되어 있다면 return
    if dp[x][y] != 1:
        return dp[x][y]

    # 4 방향으로 dfs 진행하면서 가장 큰 결과값을 현재 dp에 기록
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if nx < 0 or ny < 0 or nx >= n or ny >= n:
            continue

        if forest[nx][ny] > forest[x][y]:
            dp[x][y] = max(dp[x][y], dfs(nx,ny) + 1)

    # 4 방향 기록을 마친 후 최종적인 dp return
    return dp[x][y]
    
result = 0
for i in range(n):
    for j in range(n):
        result = max(result, dfs(i, j))

print(result)