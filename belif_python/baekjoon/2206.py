from collections import deque

n, m = map(int, input().split())

array = []
for _ in range(n):
    array.append(list(str(input())))

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

# 방문기록을 3차원 배열로 기록
visited = [[[False] * m for _ in range(n)] for _ in range(2)]
visited[0][0][0] = True

q = deque()
q.append((0, 0, 1, False))

result = -1
while q:
    # x 좌표, y 좌표, 거리, 벽 부순 여부
    x, y, dist, isBreak = q.popleft()

    # 도착지점에 왔으면 정답 기록 후 종료
    if x == n - 1 and y == m - 1:
        result = dist
        break

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if nx < 0 or ny < 0 or nx >= n or ny>= m:
            continue

        if not isBreak:
            # 벽을 부수지 않은 상태
            if visited[0][nx][ny]:
                continue

            if array[nx][ny] == '1':
                # 이 부분이 벽이라면 visited[1][][]에 기록, isBreak = True로 기록
                visited[1][nx][ny] = True
                q.append((nx, ny, dist + 1, True))
            else:
                # 벽이 아니라면 visited[0][][]에 기록, isBreak = False로 기록
                visited[0][nx][ny] = True
                q.append((nx, ny, dist + 1, False))
        else:
            # 벽을 부순 상태
            if visited[1][nx][ny]:
                continue

            # 이미 벽을 부수었는데 또 벽일 경우 continue
            if array[nx][ny] == '1':
                continue
            
            visited[1][nx][ny] = True
            q.append((nx, ny, dist + 1, True))

print(result)