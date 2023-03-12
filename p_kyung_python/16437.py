import sys
sys.setrecursionlimit(123458)
input = sys.stdin.readline

n = int(input())
tree = [[] for _ in range(n + 1)]
inf = [[], [0, 0]]

for i in range(n - 1):
    type, number, connect = input().split()
    tree[int(connect)].append(i + 2)
    inf.append([int(number), type])

def dfs(v):
    result = 0

    for i in tree[v]:
        result += dfs(i)

    if inf[v][1] == 'W':
        result -= inf[v][0]
        if result < 0:
            result = 0
    else:
        result += inf[v][0]
    return result

print(dfs(1))