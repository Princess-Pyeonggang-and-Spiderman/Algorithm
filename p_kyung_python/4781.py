import sys

input = sys.stdin.readline

while True:
    n, m = input().split()
    if n == "0" and m == "0.00":
        break
    n = int(n)
    m = int(float(m) * 100 + 0.5)
    dp = [0] * (m + 1)  # 돈이 i일 때 가장 높은 칼로리
    candy = []
    for i in range(n):
        c, p = input().split()
        candy.append([int(c), int(float(p) * 100 + 0.5)])

    for i in range(1, m + 1):
        for j in range(n):
            if i < candy[j][1]:
                continue
            dp[i] = max(dp[i], dp[i - candy[j][1]] + candy[j][0])  # 기존 칼로리에서 j번째 칼로리를 빼준 값에서 j번째 칼로리를 더함
    print(dp[m])
