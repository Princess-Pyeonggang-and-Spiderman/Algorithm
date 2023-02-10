from collections import deque

r, c, t = map(int, input().split())
house = [list(map(int, input().split())) for _ in range(r)]
air_cleaner = []

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

for i in range(r):
    if house[i][0] == -1:
        air_cleaner.append(i)

time = 0
while time < t:
    q = deque()

    # 미세 먼지가 있는 곳 찾기
    for i in range(r):
        for j in range(c):
            if house[i][j] != 0 and house[i][j] != -1:
                q.append((i, j, house[i][j]))
    
    # 미세 먼지 확산
    while q:
        x, y, amount = q.popleft()

        count = 0
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or ny < 0 or nx >= r or ny >= c:
                continue

            if house[nx][ny] == -1:
                continue
            
            house[nx][ny] += amount // 5
            count += 1
        
        house[x][y] -= (amount // 5) * count

    # 공기청정기 작동
    for i in range(air_cleaner[0] - 1, 0, -1):
        house[i][0] = house[i - 1][0]
    for i in range(air_cleaner[1] + 1, r - 1):
        house[i][0] = house[i + 1][0]
        
    for i in range(c - 1):
        house[0][i] = house[0][i + 1]
        house[r - 1][i] = house[r - 1][i + 1]

    for i in range(air_cleaner[0]):
        house[i][c - 1] = house[i + 1][c - 1]
    for i in range(r - 1, air_cleaner[1] - 1, -1):
        house[i][c - 1] = house[i - 1][c - 1]

    for i in range(c - 1, 1, -1):
        house[air_cleaner[0]][i] = house[air_cleaner[0]][i - 1]
        house[air_cleaner[1]][i] = house[air_cleaner[1]][i - 1]

    house[air_cleaner[0]][1], house[air_cleaner[1]][1] = 0, 0

    time += 1

print(sum([sum(room) for room in house]) + 2)