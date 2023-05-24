def string_bomb():
    # 문자열 폭발
    for _ in range(len(bomb)):
        stack.pop()

    # 스택에 값이 있다면 바로 직전에 있던 idx return, 없다면 0 return
    if stack:
        return stack[-1][1]
    else:
        return 0
    

string = str(input())
bomb = str(input())

stack = []
# stack에 쌓이고 있는 문자가 bomb와 몇 개째 같은지 기록하는 변수
idx = 0

for i in range(len(string)):
    if bomb[idx] == string[i]:
        # 폭탄 문자열의 idx 번째 있는 문자와 현재 탐색하는 문자가 같은 경우

        if idx == len(bomb) - 1:
            # 폭탄 문자열이 완성된 경우
            stack.append((string[i], idx))
            idx = string_bomb()
        else:
            # 폭탄 문자열이 완성되어 가는 경우 : idx 조정 및 스택에 문자열 추가
            idx += 1
            stack.append((string[i], idx))

    elif bomb[0] == string[i]:
        # 폭탄 문자열의 첫 번째 문자와 현재 탐색하는 문자가 같은 경우
        idx = 1
        stack.append((string[i], idx))

    else:
        # 폭탄 문자열과 관련이 없는 경우
        idx = 0
        stack.append((string[i], idx))

# 출력
if stack:
    for i in range(len(stack)):
        if i == len(stack) - 1:
            print(stack[i][0])
        else:
            print(stack[i][0], end="")
else:
    print("FRULA")