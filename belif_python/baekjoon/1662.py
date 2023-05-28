string = str(input())

# 문자열 수를 기록
count_stack = []

# 곱할 수를 기록
multi_stack = []

count = 0
for i in range(len(string)):
    if string[i] == "(":
        # 괄호 안의 있는 문자열과 곱할 수를 multi_stack에 push
        multi_stack.append(int(string[i - 1]))

        # 지금까지 카운트한 문자열 수를 stack에 push
        count_stack.append(count - 1)
        count = 0

        # 닫는 괄호가 나왔을 때,
        # 여는 괄호까지 pop을 하기 위하여 여는 괄호 push
        count_stack.append(string[i])

    elif string[i] == ")":
        # 여는 괄호가 나올 때까지 count_stack에서 pop하여 count
        while True:
            c = count_stack.pop()
            if c == "(":
                break
            
            count += c

        # 계산한 문자열의 길이를 count_stack에 push
        count_stack.append(multi_stack.pop() * count)
        count = 0

    else:
        count += 1

# 잔여 count와 count_stack에 있는 값들을 합하여 결과 출력
print(sum(count_stack) + count)