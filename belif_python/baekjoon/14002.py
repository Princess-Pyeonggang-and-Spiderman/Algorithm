import sys

input = sys.stdin.readline

n = int(input())
numbers = list(map(int, input().split()))

dp =  [[0, []]] * n
dp[0] = [1, [numbers[0]]]

for i in range(1, n):
    count = 0
    number = []
    for j in range(i):
        if numbers[i] > numbers[j]:
            if count < dp[j][0]:
                count = dp[j][0]
                number = dp[j][1]

    if count == 0:
        dp[i] = [count + 1, [numbers[i]]]
    else:
        dp[i] = [count + 1, number + [numbers[i]]]

max_count = 0
for i in range(n):
    if max_count < dp[i][0]:
        max_count = dp[i][0]

print(max_count)
for i in range(n):
    if dp[i][0] == max_count:
        print(' '.join(map(str, dp[i][1])))
        break