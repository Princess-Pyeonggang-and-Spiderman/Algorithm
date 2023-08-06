from collections import deque
import sys

input = sys.stdin.readline
STATE_ONE, STATE_TWO = 1, 2
k = int(input())

for _ in range(k):
    v, e = map(int, input().split())
    visited = [False] * (v + 1)
    graph = [[] for _ in range(v + 1)]

    for _ in range(e):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)

    state_info = {STATE_ONE : [], STATE_TWO : []}
    isTrue = True

    for i in range(1, v + 1):
        if visited[i]:
            continue

        q = deque()
        q.append((i, STATE_ONE))
        visited[i] = True

        while q:
            x, state = q.popleft()
            state_info[state].append(x)

            for nx in graph[x]:
                if nx in state_info[state]:
                    isTrue = False
                    break
                
                if not visited[nx]:
                    q.append((nx, STATE_TWO if state == STATE_ONE else STATE_ONE))
                    visited[nx] = True

            if not isTrue:
                break

    print("YES" if isTrue else "NO")