import sys
import heapq
input = sys.stdin.readline

n = int(input())
for i in range(n):
    m = int(input())
    li = list(map(int, input().split()))
    ans = 0
    heapq.heapify(li)
    while len(li) > 1:
        a = heapq.heappop(li)
        b = heapq.heappop(li)
        ans = ans + a + b
        heapq.heappush(li, a + b)
    print(ans)