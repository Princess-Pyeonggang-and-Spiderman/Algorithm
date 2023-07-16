def solution(n, lost, reserve):
    cloth = {}
    
    for i in range(1, n + 1):
        cloth[i] = 1
    
    for l in lost:
        cloth[l] -= 1
        
    for r in reserve:
        cloth[r] += 1

    for i in range(1, n + 1):
        if cloth[i] <= 0:
            if i - 1 in cloth and cloth[i - 1] > 1:
                cloth[i] += 1
                cloth[i - 1] -= 1
            elif i + 1 in cloth and cloth[i + 1] > 1:
                cloth[i] += 1
                cloth[i + 1] -= 1
    
    result = 0
    for value in cloth.values():
        if value >= 1:
            result += 1
    
    return result