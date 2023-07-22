import copy

n, m = map(int, input().split())
array = [list(map(str, input().split())) for _ in range(n)]

# cctv (1, 2, 3, 4, 5) 의 x, y 좌표 list
cctv_list = []

# 방향
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

# 결과 값 ("0" 의 개수)
result = 0

# cctv 좌표와 "0"의 개수를 구하기
for i in range(n):
    for j in range(m):
        if array[i][j] != "#" and array[i][j] != "0" and array[i][j] != "6":
            cctv_list.append((i, j))
        if array[i][j] == "0":
            result += 1

# direction 방향 한 줄을 모두 "#" 으로 변환
def line_check(x, y, direction, tmp_array):
    global n, m

    nx = x + dx[direction]
    ny = y + dy[direction]

    while nx >= 0 and ny >= 0 and nx < n and ny < m:
        if tmp_array[nx][ny] == "6":
            break

        if tmp_array[nx][ny] != "1" and tmp_array[nx][ny] != "2" and tmp_array[nx][ny] != "3" and tmp_array[nx][ny] != "4" and tmp_array[nx][ny] != "5":
            tmp_array[nx][ny] = "#"

        nx += dx[direction]
        ny += dy[direction]

    return tmp_array

# 브루트포스를 위한 dfs
def dfs(idx, arr):
    global result

    # 마지막까지 탐색했을 경우 "0"의 개수를 result 에 반영
    if idx >= len(cctv_list):
        result = min(result, sum(1 for i in range(n) for j in range(m) if arr[i][j] == "0"))
        return
    
    # 현재 cctv_list x, y 좌표
    x, y = cctv_list[idx]

    if arr[x][y] == "1":
        # cctv 1 ) 한 방향 4가지 경우에 대해 line check 후 각각 dfs
        for i in range(4):
            next_array = copy.deepcopy(arr)
            next_array = line_check(x, y, i, next_array)
            dfs(idx + 1, next_array)
    elif arr[x][y] == "2":
        # cctv 2 ) 두 방향 2가지 경우에 대해 (수직, 수평) line check 후 각각 dfs
        next_range = [(0, 2), (1, 3)]
        for i, j in next_range:
            next_array = copy.deepcopy(arr)
            next_array = line_check(x, y, i, next_array)
            next_array = line_check(x, y, j, next_array)
            dfs(idx + 1, next_array)
    elif arr[x][y] == "3":
        # cctv 3 ) 두 방향 4가지 경우에 대해 (직각) line check 후 각각 dfs 
        next_range = [(0, 1), (1, 2), (2, 3), (3, 0)]
        for i, j in next_range:
            next_array = copy.deepcopy(arr)
            next_array = line_check(x, y, i, next_array)
            next_array = line_check(x, y, j, next_array)
            dfs(idx + 1, next_array)
    elif arr[x][y] == "4":
        # cctv 4 ) 세 방향 4가지 경우에 대해 line check 후 각각 dfs 
        next_range = [(0, 1, 2), (1, 2, 3), (2, 3, 0), (3, 0, 1)]
        for i, j, k in next_range:
            next_array = copy.deepcopy(arr)
            next_array = line_check(x, y, i, next_array)
            next_array = line_check(x, y, j, next_array)
            next_array = line_check(x, y, k, next_array)
            dfs(idx + 1, next_array)
    elif arr[x][y] == "5":
        # cctv 5 ) 네 방향 1가지 경우에 대해 line check 후 dfs
        next_array = copy.deepcopy(arr)
        for i in range(4):
            next_array = line_check(x, y, i, next_array)
        dfs(idx + 1, next_array)

# dfs 를 이용한 브루트포스
dfs(0, array)

# 결과 출력
print(result)