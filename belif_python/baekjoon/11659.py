import sys

input = sys.stdin.readline
n, m = map(int, input().split())

numbers = list(map(int, input().split()))
dp = [0] * n

x = 0
for i in range(n):
    x += numbers[i]
    dp[i] = x

for _ in range(m):
    a, b = map(int, input().split())

    result = dp[b-1]
    if a - 2 >= 0:
        result -= dp[a-2]
    print(result)