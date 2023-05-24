import sys

input = sys.stdin.readline

while True:
    n, m = map(float, input().split())
    m = int(m * 100 + 0.5)

    if n == 0 and m == 0:
        break

    dp = [0] * (m + 1)
    bag = []

    for _ in range(int(n + 0.5)):
        c, p = map(float, input().split())
        p = int(p * 100 + 0.5)

        bag.append((c, p))

    for i in range(m + 1):
        for calorie, price in bag:
            if i - price < 0:
                continue

            dp[i] = max(dp[i], dp[i - price] + calorie)

    print(int(dp[m] + 0.5))