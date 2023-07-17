import sys

input = sys.stdin.readline

INF = int(1e9)
n, m = map(int, input().split())
edges = []
distance = [INF] * (n + 1)

# 간선 입력
for _ in range(m):
    a, b, c = map(int, input().split())
    edges.append((a, b, c))

# 시작 노드 거리를 0 으로 설정
distance[1] = 0

# 모든 노드의 개수만큼 반복
for i in range(n):
    # 모든 간선에 대해서 반복
    for start, next, cost in edges:
        # 거리 업데이트가 가능할 경우
        if distance[start] != INF and distance[start] + cost < distance[next]:
            distance[next] = distance[start] + cost

            # 처음에 start node (distance) 를 반영하였기 때문에
            # n - 1 개의 사이클을 돈 이후 부터는 사이클을 반복하여도
            # 더 이상 값이 업데이트되면 안됨 -> n - 1 에도 갱신이 될 경우 음의 사이클
            if i == n - 1:
                # 음의 사이클일 경우 -1 출력 후 종료
                print(-1)
                exit(0)

for i in range(2, n + 1):
    # 해당 노드의 도착할 수 없으면 -1 출력
    if distance[i] == INF:
        print(-1)
    else:
        print(distance[i])