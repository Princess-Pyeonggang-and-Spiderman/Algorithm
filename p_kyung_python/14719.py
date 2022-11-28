h, w = map(int, input().split())
rain = list(map(int, input().split()))
result = 0

for i in range(1, w-1):
    wall = min(max(rain[:i]), max(rain[i+1:]))
    if rain[i] < wall:
        result += wall - rain[i]
print(result)
