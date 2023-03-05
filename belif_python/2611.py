from collections import deque
import sys

input = sys.stdin.readline

n = int(input())
m = int(input())

graph = [[] for _ in range(n + 1)]
indegree = [0] * (n + 1)
dp = [[0, []] for _ in range(n + 1)] # score, route list

for _ in range(m):
    p, q, r = map(int, input().split())
    graph[p].append((q, r))
    indegree[q] += 1

q = deque()
q.append(1)

while q:
    x = q.popleft()

    # 1 -> ... -> 1 로 돌아왔을 경우 결과 출력 후 break
    if x == 1 and len(dp[1][1]) != 0:
        print(dp[x][0])
        print(' '.join(map(str, dp[x][1] + [x])))
        break

    # 다음 경로로 가는 경우
    for next_node, next_score in graph[x]:
        # dp update
        if dp[next_node][0] < dp[x][0] + next_score:
            dp[next_node][0] = dp[x][0] + next_score
            dp[next_node][1] = dp[x][1] + [x]
        
        # indegree update 후, 진입 가능 시 queue에 추가
        indegree[next_node] -= 1

        if indegree[next_node] == 0:
            q.append(next_node)