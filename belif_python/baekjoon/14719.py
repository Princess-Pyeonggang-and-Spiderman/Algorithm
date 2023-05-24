h, w = map(int, input().split())

infos = list(map(int, input().split()))

# 왼쪽 기둥
left = -1
left_index = -1

result = 0

for i in range(w):
    # 마지막 오른쪽 기둥일 때 왼쪽 기둥까지 이동하면서 빼주기
    if i == w - 1:
        if left > infos[i]:
            right = infos[i]
            for j in range(i - 1, left_index, -1):
                if infos[j] > right:
                    right = infos[j]
                result -= left - right
        break

    if left <= infos[i]:
        left = infos[i]
        left_index = i
    else:
        # 왼쪽 기둥보다 현재 기둥이 낮을 경우 hole에 물 채우기
        result += left - infos[i]

print(result)