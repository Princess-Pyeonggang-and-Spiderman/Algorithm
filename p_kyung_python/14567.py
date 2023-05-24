from collections import deque
import sys

n, m = map(int, sys.stdin.readline().split())

sub = [[] for i in range(n + 1)]
indegree = [0 for i in range(n + 1)]
result = [1 for i in range(n + 1)]
for i in range(m):
    a, b = map(int, sys.stdin.readline().split())
    sub[a].append(b)
    indegree[b] += 1

q = deque()
for i in range(1, n + 1):
    if indegree[i] == 0:
        q.append(i)

while q:
    now = q.popleft()
    for i in sub[now]:
        indegree[i] -= 1
        if indegree[i] == 0:
            q.append(i)
            result[i] = result[now] + 1  # 학기 추가하기

for i in range(1, n + 1):
    print(result[i], end = ' ')

