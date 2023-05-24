from itertools import combinations

visited = 0
n, k = map(int, input().split())
words = []

for _ in range(n):
    words.append(str(input()))

if k < 5:
    print(0)
    exit(0)

# a = 97
default = ["a", "c", "i", "n", "t"]
alpha = ["b", "d", "e", "f", "g", "h", "j", "k", "l", "m", "o", "p", "q", "r", "s", "u", "v", "w", "x", "y", "z"]

for al in default:
    visited |= 1 << (26 - (ord(al) - 97))

max_result = 0
for al in list(combinations(alpha, k - 5)):
    result = 0
    v = visited
    for a in al:
        v |= 1 << (26 - (ord(a) - 97))
    
    for word in words:
        isTrue = True
        for w in word:
            if not (v >> (26 - (ord(w) - 97))) & 1:
                isTrue = False
                break
        
        if isTrue:
            result += 1
    
    max_result = max(max_result, result)

print(max_result)