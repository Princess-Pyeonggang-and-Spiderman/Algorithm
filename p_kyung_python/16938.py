import sys
import itertools

input = sys.stdin.readline

n, l, r, x = map(int, input().split())
camp = list(map(int, input().split()))
cnt = 0

for i in range(n, 1, -1):
    com = list(itertools.combinations(camp, i))
    for j in range(len(com)):
        if l <= sum(com[j]) <= r and max(com[j]) - min(com[j]) >= x:
            cnt += 1


print(cnt)
