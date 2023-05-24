from itertools import combinations
import sys

input = sys.stdin.readline
n ,l, r, x = map(int, input().split())
level = list(map(int, input().split()))
result = 0

for i in range(2, n + 1):
    level_list = list(combinations(level, i))

    for li in level_list:
        if l <= sum(li) <= r and max(li) - min(li) >= x:
            result += 1

print(result)