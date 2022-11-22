# 퇴사 14501
# result[i]에는 i번째 날까지 일했을 때의 최댓값을 저장
# 시간 복잡도 O(n^2)

cnt = int(input())
day = [0 for _ in range(cnt+1)]
money = [0 for _ in range(cnt+1)]
result = [0 for _ in range(cnt+1)]

for i in range(cnt):
    d, m = map(int, input().split())
    day[i] = d
    money[i] = m

for i in range(cnt+1):
    for j in range(i+day[i], cnt+1):
        if (result[j] < money[i] + result[i]):
            result[j] = money[i] + result[i]
print(result[cnt])
