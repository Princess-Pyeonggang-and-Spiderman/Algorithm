import sys

input = sys.stdin.readline
n, m = map(int, input().split())

# 입력
dp = [[0] * (n + 1) for _ in range(n + 1)]
array = []

for _ in range(n):
    array.append(list(map(int, input().split())))

# DP 업데이트
for i in range(1, n + 1):
    for j in range(1, n + 1):
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + array[i - 1][j - 1]

# DP 에서 값 추출해서 주어진 답 구하기
for _ in range(m):
    x1, y1, x2, y2 = map(int, input().split())

    '''
    minux_index1 = (x1 - 1, y2)
    minux_index2 = (x2, y1 - 1)
    plus_index = (x1 - 1, y1 - 1)
    '''

    result = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1]
    
    print(result)