s = input()
a = ""
length = 0
stack = []

for i in s:
    if i == '(':
        stack.append(a)
        stack.append(length - 1)
        length = 0
    elif i == ')':
        preLen = stack.pop()
        mul = stack.pop()
        length = (int(mul) * length) + preLen
    else:
        length += 1
        a = i

print(length)