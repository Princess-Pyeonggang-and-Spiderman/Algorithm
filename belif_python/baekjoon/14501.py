# 이 문제는 마지막 날부터 일을 한다고 생각하여 dp top-down 방식으로 풀이

n = int(input())

# top down 방식에서 처음에 다음 값과 비교를 할 때를 대비해 n + 2 로 설정
dp = [0] * (n + 2)
infos = []

# 입력
for _ in range(n):
    infos.append(list(map(int, input().split())))

# n ~ 1 까지 반복
for i in range(n, 0, -1):
    t = infos[i-1][0] # 기간
    p = infos[i-1][1] # 금액

    # i - 1 + t -> i일부터 일을 했을 때, 끝나는 날짜
    # 예) if i == 8, t == 3 ) 8, 9, 10일 일을 하므로
    #     끝나는 날짜 : 8 - 1 + 3 = 10
    if i-1 + t > n:
        # i일에 일을 했을 때, n일까지 일을 끝내지 못할 경우
        dp[i] = dp[i+1]
    else:
        # n일까지 일을 마칠 수 있는 경우, 더 큰 값을 비교
        dp[i] = max(dp[i+1], dp[i+t] + p)

print(dp[1])