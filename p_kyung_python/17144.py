from collections import deque

r, c, t = map(int, input().split())
board = []
upAir = 0
downAir = 0
time = 0
sum = 0
dx = [-1, 0, 0, 1]
dy = [0, -1, 1, 0]
for i in range(r):
    board.append(list(map(int, input().split())))

for i in range(r):
    if board[i][0] == -1:
        upAir = i
        downAir = i + 1
        break


def diffusion():
    dust = deque()
    for i in range(r):
        for j in range(c):
            if board[i][j] > 0:
                dust.append((i, j, board[i][j]))
    while dust:
        x, y, a = dust.pop()
        cnt = 0
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= r or ny >= c:
                continue
            if board[nx][ny] == -1:
                continue
            board[nx][ny] += a // 5
            cnt += 1
        board[x][y] -= (a // 5) * cnt


def wind():
    for i in range(upAir - 1, 0, -1):
        board[i][0] = board[i - 1][0]
    for i in range(downAir + 1, r - 1):
        board[i][0] = board[i + 1][0]
    for i in range(c - 1):
        board[0][i] = board[0][i + 1]
        board[r - 1][i] = board[r - 1][i + 1]
    for i in range(upAir):
        board[i][c - 1] = board[i + 1][c - 1]
    for i in range(r - 1, downAir, -1):
        board[i][c - 1] = board[i - 1][c - 1]
    for i in range(c - 1, 0, -1):
        board[upAir][i] = board[upAir][i - 1]
        board[downAir][i] = board[downAir][i - 1]

while time < t:
    diffusion()
    wind()
    board[upAir][1], board[downAir][1] = 0, 0
    time += 1


for i in range(r):
    for j in range(c):
        if board[i][j] != -1:
            sum += board[i][j]
print(sum)