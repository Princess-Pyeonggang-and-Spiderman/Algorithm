import sys

input = sys.stdin.readline
m = int(input())

result = 0
for _ in range(m):
    commands = list(map(str, input().split()))

    if len(commands) == 1:
        if commands[0] == "all":
            result |= ~0
        elif commands[0] == "empty":
            result = 0
        continue

    command, number = commands[0], int(commands[1])
    bitNumber = (1 << (number - 1))

    if command == "add":
        result |= bitNumber
    elif command == "remove":
        result &= ~bitNumber
    elif command == "check":
        print((result >> (number - 1)) & 1)
    elif command == "toggle":
        result ^= bitNumber