from collections import deque
import sys

input = sys.stdin.readline
n = int(input())

# 시간과 차수 정보 저장
time = [0] * (n + 1)
indegree = [0] * (n + 1)

# i 번째 작업을 완료하면 graph 의 i 번째 리스트에
# 기록되어 있는 작업들의 차수를 모두 줄여주도록 하는 방법 사용
graph = [[] for _ in range(n + 1)]
q = deque()

# 입력 받으면서 차수가 0 인 부분 q 에 초기 설정
for i in range(n):
    inputs = list(map(int, input().split()))
    time[i + 1] = inputs[0]
    indegree[i + 1] = inputs[1]

    for j in range(2, len(inputs)):
        graph[inputs[j]].append(i + 1)

    if inputs[1] == 0:
        q.append((i + 1, 0))

result = 0
while q:
    x, count = q.popleft()

    result = count
    time[x] -= 1

    if time[x] == 0:
        # 작업 완료 시, 다음 작업 차수 줄이기
        for next in graph[x]:
            indegree[next] -= 1

            # 다음 작업을 수행할 수 있는 경우 q 에 추가
            if indegree[next] == 0:
                q.append((next, count + 1))
    else:
        # 작업 미완료 시, 시간만 증가 시킨 후 다시 q 에 추가
        q.append((x, count + 1))

# 마지막 작업 count 가 되지 않으므로 +1 을 하여 정답 출력
print(result + 1)