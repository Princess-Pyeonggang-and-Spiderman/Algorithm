n = int(input())

ORD_A = 65
start_node = 0
graph = [[] for _ in range(n)]

for i in range(n):
    a, b, c = map(str, input().split())
    graph[ord(a) - ORD_A].append(b)
    graph[ord(a) - ORD_A].append(c)
    if i == 0:
        start_node = a

def dfs_preorder(x):
    left, right = graph[ord(x) - ORD_A]

    print(x, end="")
    if left != ".":
        dfs_preorder(left)
    if right != ".":
        dfs_preorder(right)

def dfs_inorder(x):
    left, right = graph[ord(x) - ORD_A]

    if left != ".":
        dfs_inorder(left)
    print(x, end="")
    if right != ".":
        dfs_inorder(right)

def dfs_postorder(x):
    left, right = graph[ord(x) - ORD_A]

    if left != ".":
        dfs_postorder(left)
    if right != ".":
        dfs_postorder(right)
    print(x, end="")

dfs_preorder(start_node)
print()
dfs_inorder(start_node)
print()
dfs_postorder(start_node)
print()