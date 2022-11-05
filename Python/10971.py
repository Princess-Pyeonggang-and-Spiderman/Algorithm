import sys

# 재귀 제한 늘리기
sys.setrecursionlimit(10**6)

# n 과 graph 입력받기
n = int(input())
graph = []
for _ in range(n):
    graph.append(list(map(int, input().split())))
    
results = []
# x = 현재 노드, visited = 방문 여부 배열, result = 결과값, count = 지금까지 방문한 노드 개수
def dfs(x, visited, result, count):
    # 모든 노드를 방문하고 시작 지점으로 돌아온 경우
    if count == n+1 and x == 0:
        results.append(result)
        
    for i in range(n):
        # 모든 노드를 방문하지 않았는데 시작 지점으로 가려는 경우 continue
        if count != n and i == 0:
            continue
        # graph 상에서 갈 수 없는 곳이거나 이미 방문한 곳인 경우 continue
        if graph[x][i] == 0 or visited[i]:
            continue

        visited[i] = True
        dfs(i, visited, result + graph[x][i], count + 1)
        visited[i] = False

# 0에서부터 시작하여 dfs 진행
# 외판원 순회 문제는 0 -> 1 -> 2 -> 0 처럼 각 노드에서 출발하는 것과 각 노드로 들어오는 것이
# 모두 필요하므로 어디에서 시작하던지 상관이 없기 때문에 0에서 시작하도록 설정
# (0 -> 1 -> 2 -> 0 과 1 -> 2 -> 0 -> 1 의 의미가 같다.)
v = [False] * (n+1)
dfs(0, v, 0, 1)

print(min(results))
