from collections import deque
import sys

sys.setrecursionlimit(10 ** 6)

# 재귀적 출력
def print_dfs(x):
    global k

    if x == n:
        print(x, end=' ')
    else:
        print_dfs(visited[x])
        if x == k:
            print(x)
        else:
            print(x, end=' ')

INF = int(1e9)
n, k = map(int, input().split())

# visited[x] : x 로 오기 이전 노드 (INF 일 경우 이전 노드 x)
visited = [INF] * 100001

q = deque()
q.append((n, 0))

while q:
    x, time = q.popleft()

    # 찾았을 경우 정답 출력 후 return
    if x == k:
        print(time)
        print_dfs(x)
        break

    # 이동 경로 (+1, -1, *2)
    dx = [x * 2, x + 1, x - 1]

    for i in range(3):
        nx = dx[i]

        # 0 * 2 or 범위 초과 or 이미 방문했을 경우 continue
        if x == nx or nx < 0 or nx > 100000 or visited[nx] != INF:
            continue

        # 이전 경로 기록, q에 append 하여 bfs 수행
        visited[nx] = x
        q.append((nx, time + 1))