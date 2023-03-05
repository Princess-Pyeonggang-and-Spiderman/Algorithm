from collections import deque
import sys

input = sys.stdin.readline

while True:
    n, k = map(int, input().split())
    if n == 0 and k == 0:
        break

    # 트리 셋팅
    tree = [[] for _ in range(n + 1)]
    parent = [-1] * n
    numbers = list(map(int, input().split()))

    parent_idx = -1
    k_idx = 0

    for i in range(1, n):
        parent_idx += 1 if numbers[i] != numbers[i - 1] + 1 else 0
        tree[parent_idx].append(i)
        parent[i] = parent_idx
        
        if numbers[i] == k:
            k_idx = i

    # k 의 depth 확인
    k_depth = 0
    idx = k_idx
    while idx != 0:
        idx = parent[idx]
        k_depth += 1

    # 사촌의 수 찾기
    q = deque()
    q.append((0, 0))
    result = 0

    while q:
        x, depth = q.popleft()

        if depth == k_depth - 1:
            if x != parent[k_idx] and parent[x] == parent[parent[k_idx]]:
                result += len(tree[x])
            continue
        
        for next_idx in tree[x]:
            q.append((next_idx, depth + 1))

    print(result)