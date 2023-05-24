# 백준 11048 이동하기

n, m = map(int, input().split())
candy = [[0] * m for i in range(n)]
result = [[0] * m for i in range(n)]

for i in range(n):
    candy[i] = list(map(int, input().split()))

for i in range(0, n):
    for j in range(0, m):
        if (i-1 < 0 and j-1 < 0):
            result[i][j] = candy[i][j]
            continue
        elif (i-1 < 0 and j-1 >= 0):
            result[i][j] = result[i][j-1] + candy[i][j]
            continue
        elif (i-1 >= 0 and j-1 < 0):
            result[i][j] = result[i-1][j] + candy[i][j]
            continue
        result[i][j] = max(result[i-1][j], result[i][j-1]) + candy[i][j]
print(result[n-1][m-1])
