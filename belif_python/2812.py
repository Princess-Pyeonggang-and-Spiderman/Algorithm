n, k = map(int, input().split())
number = str(input())

stack = []

count = 0
for i in range(n):
    if not stack:
        stack.append(number[i])
    else:
        while stack and stack[-1] < number[i] and count < k:
            count += 1
            stack.pop()
        stack.append(number[i])

# count 만큼 지워지지 않았을 경우 ( 예) 54321 ) 
while count < k:
    stack.pop()
    count += 1

print(''.join(stack))