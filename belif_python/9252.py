first = str(input())
second = str(input())

# first : 가로, second : 세로
dp = [[""] * (len(first) + 1) for _ in range(len(second) + 1)]

for j in range(1, len(first) + 1):
    for i in range(1, len(second) + 1):
        if first[j - 1] == second[i - 1]:
            dp[i][j] = dp[i - 1][j - 1] + first[j - 1]
        else:
            if len(dp[i][j - 1]) >= len(dp[i - 1][j]):
                dp[i][j] = dp[i][j - 1]
            else:
                dp[i][j] = dp[i - 1][j]

result = dp[len(second)][len(first)]
print(len(result))
print(result)