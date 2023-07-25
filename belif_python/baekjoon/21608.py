n = int(input())

# array : 자리, like_numbers : 좋아하는 학생 (hash-map), s_c : 자리 배치 순서
array = [[0] * n for _ in range(n)]
like_numbers = {}
sequence_number = []
di = [0, 1, 0, -1]
dj = [1, 0, -1, 0]

# 입력
for _ in range(n * n):
    tmp = list(map(int, input().split()))

    like_numbers[tmp[0]] = tmp[1:]
    sequence_number.append(tmp[0])

# 자리 배치 순서에 따라 배치
for number in sequence_number:
    # 후보 저장 (좋아하는 학생 수, 비어있는 자리 수, 행 번호, 열 번호)
    candidate = []

    # 모든 칸에 대해서 조사
    for i in range(n):
        for j in range(n):
            # 이미 자리가 찼으면 continue
            if array[i][j] != 0:
                continue

            # 주변에 좋아하는 학생 수, 비어있는 자리 수 count
            like_number = like_numbers[number]
            like_count = 0
            empty_count = 0
            for k in range(4):
                ni = i + di[k]
                nj = j + dj[k]

                if ni < 0 or nj < 0 or ni >= n or nj >= n:
                    continue
                
                empty_count = empty_count + 1 if array[ni][nj] == 0 else empty_count
                like_count = like_count + 1 if array[ni][nj] in like_number else like_count
                
            candidate.append((like_count, empty_count, i, j))

    # 우선순위가 높은 후보로 자리 선정
    candidate.sort(key=lambda x: (-x[0], -x[1], x[2], x[3]))
    array[candidate[0][2]][candidate[0][3]] = number

# 자리 결과에 따른 만족도의 총합 구하기
result = 0
for i in range(n):
    for j in range(n):
        like_number = like_numbers[array[i][j]]

        # 주변에 좋아하는 학생 수 count
        count = 0
        for k in range(4):
            ni = i + di[k]
            nj = j + dj[k]

            if ni < 0 or nj < 0 or ni >= n or nj >= n:
                continue

            count = count + 1 if array[ni][nj] in like_number else count

        # 만족도 계산하여 반영
        if count == 0 or count == 1:
            result += count
        elif count == 2:
            result += 10
        elif count == 3:
            result += 100
        elif count == 4:
            result += 1000
            
print(result)