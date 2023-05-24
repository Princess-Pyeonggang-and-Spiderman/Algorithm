n = int(input())
numbers = [int(input()) for _ in range(n)]

dp =  [0] * n

for i in range(n):
    for j in range(i):
        if numbers[i] > numbers[j]:
            dp[i] = max(dp[i], dp[j])

    dp[i] += 1

print(n - max(dp))