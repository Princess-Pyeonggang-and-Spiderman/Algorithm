from itertools import combinations
from collections import deque

classroom = [list(str(input())) for _ in range(5)]

# 반 학생 중 7명을 랜덤으로 뽑는 모든 경우의 수
sevens = list(combinations([(i, j) for i in range(5) for j in range(5)], 7))

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

result = 0

for seven in sevens:
    # 4명 이상이 "S" 인지 확인
    if sum(1 for i in range(7) if classroom[seven[i][0]][seven[i][1]] == "S") < 4:
        continue

    # 7명이 인접하게 연결되어 있는지 확인
    visited = [False] * 7
    visited[0] = True

    q = deque()
    q.append(seven[0])

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or ny < 0 or nx >= 5 or ny >= 5:
                continue
            
            # 인접한 학생이 있으면 다음 학생으로 바통 터치
            for i in range(7):
                if seven[i] == (nx, ny) and not visited[i]:
                    visited[i] = True
                    q.append((nx, ny))
                    break
    
    # 모두 연결되어 있는 경우 결과에 반영
    result += 1 if not False in visited else 0

print(result)