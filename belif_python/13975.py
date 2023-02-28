import sys, heapq

input = sys.stdin.readline
t = int(input())

for _ in range(t):
    k = int(input())
    numbers = list(map(int, input().split()))
    q = []

    for number in numbers:
        heapq.heappush(q, number)

    result = 0
    while len(q) > 1:
        a = heapq.heappop(q)
        b = heapq.heappop(q)

        result += a + b
        heapq.heappush(q, a + b)

    print(result)