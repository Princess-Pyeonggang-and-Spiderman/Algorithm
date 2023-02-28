import sys
input = sys.stdin.readline

n = int(input())
cnt = 0
number = list(map(int, input().split()))
number.sort()

for i in range(n):
    s = 0
    e = len(number) - 1
    while s < e:
        if number[s] + number[e] == number[i]:
            if s == i:
                s += 1
            elif e == i:
                e -= 1
            else:
                cnt += 1
                break
        elif number[s] + number[e] < number[i]:
            s += 1
        else:
            e -= 1

print(cnt)
