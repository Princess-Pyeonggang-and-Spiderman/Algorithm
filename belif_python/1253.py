def binary_search(start, end, x):
    if start >= end:
        return

    mid = (start + end) // 2

    if numbers[x] + numbers[mid] > numbers[-1]:
        binary_search(start, mid, x)
    else:
        for i in range(n):
            if i == x or i == mid:
                continue
            if numbers[x] + numbers[mid] == numbers[i]:
                visited[numbers[x] + numbers[mid]] = True
                break
    
        binary_search(start, mid, x)
        binary_search(mid + 1, end, x)

n = int(input())
numbers = list(map(int, input().split()))
numbers.sort()

visited = {}

for i in range(n - 1):
    binary_search(i + 1, n - 1, i)

print(sum(1 for number in numbers if number in visited))