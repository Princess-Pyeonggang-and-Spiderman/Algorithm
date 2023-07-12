from collections import deque
import sys

input = sys.stdin.readline

n, m, k = map(int, input().split())

# 양분 정보 2차원 배열 (초기값 5)
array = [[5] * n for _ in range(n)]
# 로봇 양분 추가 정보 배열
s2d2 = [list(map(int, input().split())) for _ in range(n)]

# 3차원 배열 (x 좌표, y 좌표, age)
trees = [[[] for _ in range(n)] for _ in range(n)]

for _ in range(m):
    x, y, z = map(int, input().split())
    trees[x - 1][y - 1].append(z)

# 이동 좌표
dx = [0, 1, 0, -1, -1, 1, -1, 1]
dy = [1, 0, -1, 0, -1, 1, 1, -1]

# k 년 동안 반복
for _ in range(k):
    # 봄
    for i in range(n):
        for j in range(n):
            # 살아있는 나무들 탐색
            if not trees[i][j]:
                continue
            
            # 좌표가 같다면 나이가 적은 순서대로 양분 먹기
            sort_tree = sorted(trees[i][j])

            # 양분 먹인 tree 결과
            result_tree = []

            # 나무를 바로 죽이면서 얻는 에너지 총합
            die_energy = 0

            for age in sort_tree:
                if age <= array[i][j]:
                    # 양분이 충분하다면 양분 먹고 나이 1 증가
                    array[i][j] -= age
                    result_tree.append(age + 1)
                else:
                    # 양분이 부족하다면 죽이고 에너지 축적
                    die_energy += age // 2
            
            # 양분 먹이고 난 후 tree 결과를 현재 trees 에 반영
            trees[i][j] = result_tree

            # 여름 -> 나무 죽인 에너지 적용
            array[i][j] += die_energy

    # 가을
    for i in range(n):
        for j in range(n):
            for age in trees[i][j]:
                # 나이가 5의 배수라면 주변 8 군데에 나이가 1인 나무 추가
                if age % 5 == 0:
                    for a in range(len(dx)):
                        nx = i + dx[a]
                        ny = j + dy[a]

                        if nx < 0 or ny < 0 or nx >= n or ny >= n:
                            continue

                        trees[nx][ny].append(1)

    # 겨울
    for i in range(n):
        for j in range(n):
            # S2D2 로봇이 모든 땅에 입력으로 주어진 양분을 추가
            array[i][j] += s2d2[i][j] 

result = 0
for i in range(n):
    for j in range(n):
        result += len(trees[i][j])

print(result)