def solution(array, commands):
    answer = []
    
    for command in commands:
        i, j, k = command
        x = array[i - 1:j]
        x.sort()
        answer.append(x[k - 1])
    
    return answer