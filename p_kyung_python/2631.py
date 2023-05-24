import sys
input = sys.stdin.readline

n = int(input())
li = []
result = [1 for _ in range(n)]

for i in range(n):
    li.append(int(input()))


for i in range(n):
    for j in range(i):
        if li[i] > li[j]:
            result[i] = max(result[i], result[j] + 1)

print(n - max(result))