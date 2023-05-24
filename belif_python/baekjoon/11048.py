n, m = map(int, input().split())

dp = [[0] * m for _ in range(n)]
array = [] 

for _ in range(n):
    array.append(list(map(int, input().split())))

for i in range(n):
    for j in range(m):
        cost = dp[i][j] + array[i][j]
        if i + 1 < n:
            dp[i + 1][j] = max(dp[i + 1][j], cost)
        if j + 1 < m:
            dp[i][j + 1] = max(dp[i][j + 1], cost)
        if i + 1 < n and j + 1 < m:
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], cost)

print(dp[n - 1][m - 1] + array[n - 1][m - 1])