def dfs(x, depth, idx):
    global result, n

    # x 에 값 더하기
    x = x + numbers[idx]

    # 3 개 탐색 시 확인 후 return
    if depth == 3:
        # 값이 조건에 만족한다면 최대값으로 저장
        if x in numbers_dict:
            result = max(result, x)
        return
    
    # x, y, z, k 가 서로 같아도 되기 때문에 idx 부터 시작
    for i in range(idx, n):
        dfs(x, depth + 1, i)

# n 입력
n = int(input())

# numbers_dict : key, value 형태로 저장하며, 
# 숫자가 있는지 체크하는데 시간을 줄이기 위해 사용
numbers_dict = {}
numbers = []
result = 0

# 입력
for _ in range(n):
    x = int(input())
    numbers_dict[x] = True
    numbers.append(x)

# 모든 경우의 수 탐색
for i in range(n):
    dfs(0, 1, i)

print(result)