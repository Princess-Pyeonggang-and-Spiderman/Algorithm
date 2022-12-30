import heapq

n, k = map(int, input().split())

distance = [int(1e9)] * 100001
q = []

distance[n] = 0
heapq.heappush(q, (0, n))

dx = [1, -1]

while q:
    dist, x = heapq.heappop(q)

    if distance[x] < dist:
        continue

    nx = x * 2
    if nx <= 100000 and distance[nx] > dist:
        distance[nx] = dist
        heapq.heappush(q, (dist, nx))

    for i in range(2):
        nx = x + dx[i]
        if nx < 0 or nx > 100000:
            continue

        cost = dist + 1
        if distance[nx] > cost:
            distance[nx] = cost
            heapq.heappush(q, (cost, nx))


print(distance[k])