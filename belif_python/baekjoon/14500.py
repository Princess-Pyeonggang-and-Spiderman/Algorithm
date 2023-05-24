n, m = map(int, input().split())

array = []

for _ in range(n):
    array.append(list(map(int, input().split())))


def tetromino(i, j):
    results = []

    # 1번 테트로미노
    if i + 3 < n:
        results.append(array[i][j] + array[i+1][j] + array[i+2][j] + array[i+3][j])
    if j + 3 < m:
        results.append(array[i][j] + array[i][j+1] + array[i][j+2] + array[i][j+3])
    
    # 2번 테트로미노
    if i + 1 < n and j + 1 < m:
        results.append(array[i][j] + array[i+1][j] + array[i][j+1] + array[i+1][j+1])

    # 3번 테트로미노
    if i + 2 < n and j + 1 < m:
        tmp = array[i][j] + array[i+1][j] + array[i+2][j]
        tmp2 = array[i][j+1] + array[i+1][j+1] + array[i+2][j+1]
        results.append(tmp + array[i][j+1])
        results.append(tmp + array[i+2][j+1])
        results.append(tmp2 + array[i][j])
        results.append(tmp2 + array[i+2][j])
    
    if i + 1 < n and j + 2 < m:
        tmp = array[i][j] + array[i][j+1] + array[i][j+2]
        tmp2 = array[i+1][j] + array[i+1][j+1] + array[i+1][j+2]
        results.append(tmp + array[i+1][j])
        results.append(tmp + array[i+1][j+2])
        results.append(tmp2 + array[i][j])
        results.append(tmp2 + array[i][j+2])

    # 4번 테트로미노
    if i + 2 < n and j + 1 < m:
        results.append(array[i][j] + array[i+1][j] + array[i+1][j+1] + array[i+2][j+1])
        results.append(array[i][j+1] + array[i+1][j+1] + array[i+1][j] + array[i+2][j])

    if i + 1 < n and j + 2 < m:
        results.append(array[i][j] + array[i][j+1] + array[i+1][j+1] + array[i+1][j+2])
        results.append(array[i+1][j] + array[i+1][j+1] + array[i][j+1] + array[i][j+2])

    # 5번 테트로미노
    if i + 1 < n and j + 2 < m:
        results.append(array[i][j] + array[i][j+1] + array[i][j+2] + array[i+1][j+1])
        results.append(array[i][j+1] + array[i+1][j] + array[i+1][j+1] + array[i+1][j+2])

    if i + 2 < n and j + 1 < m:
        results.append(array[i][j] + array[i+1][j] + array[i+2][j] + array[i+1][j+1])
        results.append(array[i+1][j] + array[i][j+1] + array[i+1][j+1] + array[i+2][j+1])

    return max(results) if len(results) != 0 else 0


result = 0
for i in range(n):
    for j in range(m):
        result = max(result, tetromino(i, j))

print(result)