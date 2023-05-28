import sys

def find_palindrome(start, end):
    # 양 옆으로 이동하며 탐색
    while start >= 0 and end < n:
        # 팰린드롬이면 dp 에 추가, 아니라면 break
        if numbers[start] != numbers[end]:
            break

        dp[(end - start + 1) % 2][i] += 1
        start, end = start - 1, end + 1

# 입력
input = sys.stdin.readline
n = int(input())
numbers = list(map(int, input().split()))
m = int(input())

# 팰린드롬 dp 생성 (짝수, 홀수)
dp = [[0] * n for _ in range(2)]

for i in range(n):
    # 홀수 개 탐색
    find_palindrome(i - 1, i + 1)
    # 짝수 개 탐색
    find_palindrome(i, i + 1)


# 입력 범위 팰린드롬 확인 후 출력
results = []
for _ in range(m):
    a, b = map(int, input().split())
    a, b = a - 1, b - 1

    mid = (a + b) // 2
    print(0 if b - mid > dp[(b - a + 1) % 2][mid] else 1)