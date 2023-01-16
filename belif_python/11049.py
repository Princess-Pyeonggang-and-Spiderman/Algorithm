import sys

input = sys.stdin.readline
n = int(input())
INF = int(1e9)

matrix = [list(map(int, input().split())) for _ in range(n)]

dp = [[0] * n for _ in range(n)]

# i : 대각선의 순서만큼 반복
# j : 대각선 상에서의 데이터 개수 만큼 반복
# k : 비교하는 횟수만큼 반복
for i in range(1, n):
    for j in range(n - i):
        x = j
        y = j + i

        dp[x][y] = INF 
        for k in range(i):
            dp[x][y] = min(dp[x][y], dp[x][y + k - i] + dp[x + k + 1][y] + matrix[x][0] * matrix[y][1] * matrix[x + k + 1][0])
            
print(dp[0][n - 1])

# 0   AB  ABC ABCD
# 0   0   BC  BCD
# 0   0   0   CD
# 0   0   0   0

# 0      AB     ABC    ABCD   ABCDE
# 0      0      BC     BCD    BCDE
# 0      0      0      CD     CDE
# 0      0      0      0      DE
# 0      0      0      0      0

# 재귀로 해서 탑다운으로 간단하게 풀이한 것은 (AB)(CD) 불가하여 변경
# 반례
# 5
# 1 10
# 10 1
# 1 10
# 10 1
# 1 10