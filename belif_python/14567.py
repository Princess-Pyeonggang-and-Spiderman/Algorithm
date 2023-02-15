from collections import deque
import sys

input = sys.stdin.readline
n, m = map(int, input().split())

graph = [[] for _ in range(n + 1)]
indegree = [0] * (n + 1)
result = [0] * n
q = deque()

for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    indegree[b] += 1

# 차수가 0인 과목 q에 push
for i in range(1, n + 1):
    if indegree[i] == 0:
        q.append((i, 1))

while q:
    x, count = q.popleft()

    # 이수할 학기 기록
    result[x - 1] = count

    # 선수과목 이수 후 다음 이수할 과목 확인 및 설정
    for g in graph[x]:
        indegree[g] -= 1
        if indegree[g] == 0:
            q.append((g, count + 1))

print(' '.join(map(str, result)))