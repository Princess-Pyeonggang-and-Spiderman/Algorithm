import sys
input = sys.stdin.readline

n, k = -1, -1

while True:
    n, k = map(int, input().split())
    if n == 0 and k == 0:
        break
    li = [-1] + list(map(int, input().split()))
    parent = [0 for i in range(n + 1)]
    parent[0] = -1
    idx = -1
    target = 0
    for i in range(1, n + 1):  # 부모 노드의 인덱스를 parent에 저장
        if li[i] == k:
            target = i
        if li[i] != li[i - 1] + 1:  # 연속 되어 있으면 idx 증가 시키고 저장
            idx += 1
        parent[i] = idx
    ans = 0
    for i in range(1, n + 1):
        if parent[i] != parent[target] and parent[parent[i]] == parent[parent[target]]:
            ans += 1
    print(ans)
