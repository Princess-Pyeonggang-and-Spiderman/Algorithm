n = int(input())
snows = list(map(int, input().split()))
snows.sort()

result = int(1e9)

for i in range(n):
    for j in range(i + 1, n): 
        x_idx, y_idx = j + 1, j + 1

        while x_idx < n and y_idx < n:
            # index 가 겹칠 경우 작은 쪽 인덱스 늘려주기
            if x_idx == y_idx:
                if snows[x_idx] <= snows[y_idx]:
                    x_idx += 1
                else:
                    y_idx += 1

            # index 가 범위 밖으로 넘어가면 종료
            if x_idx >= n or y_idx >= n:
                break
            
            # 차이값이 작은 결과 기록
            result = min(result, abs((snows[i] + snows[x_idx]) - (snows[j] + snows[y_idx])))

            # 키가 작은 쪽의 point 증가
            if snows[i] + snows[x_idx] < snows[j] + snows[y_idx]:
                x_idx += 1
            elif snows[i] + snows[x_idx] > snows[j] + snows[y_idx]:
                y_idx += 1
            else:
                print(0)
                exit(0)

print(result)