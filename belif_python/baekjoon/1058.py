n = int(input())

friends = []
friends_2 = [0] * n

for _ in range(n):
    friends.append(list(str(input())))

for i in range(n):
    for j in range(n):
        if i == j:
            continue
        
        if friends[i][j] == "Y":
            friends_2[i]+= 1
            continue

        for k in range(n):
            if friends[i][k] == "Y" and friends[k][j] == "Y":
                friends_2[i] += 1
                break

print(max(friends_2))