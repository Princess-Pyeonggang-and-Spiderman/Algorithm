from bisect import bisect_left, bisect_right
import sys

# key, value dict (x 기준, y 기준)
n, m = map(int, sys.stdin.readline().split())
x_aliens, y_aliens = {}, {}

# x 좌표 y 좌표에 따라 x_aliens, y_aliens의 value로 list 구성
for _ in range(n):
    x, y = map(int, sys.stdin.readline().split())
    if x_aliens.get(x):
        x_aliens[x].append(y)
    else:
        x_aliens[x] = [y]

    if y_aliens.get(y):
        y_aliens[y].append(x)
    else:
        y_aliens[y] = [x]

commands = str(input())

# 이분 탐색을 위해 각 value list 정렬
for key, value in x_aliens.items():
    x_aliens[key] = sorted(value)
for key, value in y_aliens.items():
    y_aliens[key] = sorted(value)

# 현재 x, y를 이동시키며 최종 x, y를 결과로 출력
current_x, current_y = 0, 0
for command in commands:
    if command == "U":
        # UP, x 좌표는 고정이므로 x_aliens에서 current_x를 key로 가지는 value list에서 다음 y 좌표를 찾음
        current_y = x_aliens[current_x][bisect_right(x_aliens[current_x], current_y)]
    elif command == "D":
        # DOWN, "U"와 마찬가지로 찾지만 bisect_left를 사용하여 왼쪽에 있는 값을 다음 y 좌표로 지정
        current_y = x_aliens[current_x][bisect_left(x_aliens[current_x], current_y) - 1]
    elif command == "R":
        # RIGHT, y 좌표는 고정이므로 y_aliens에서 current_y를 key로 가지는 value list에서 다음 x 좌표를 찾음
        current_x = y_aliens[current_y][bisect_right(y_aliens[current_y], current_x)]
    elif command == "L":
        # LEFT, "R"과 마찬가지로 찾지만 bisect_left를 사용하여 왼쪽에 있는 값을 다음 x 좌표로 지정
        current_x = y_aliens[current_y][bisect_left(y_aliens[current_y], current_x) - 1]

print(current_x, current_y)