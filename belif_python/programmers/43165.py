def dfs(n, numbers, target, depth, result):
    if n == depth:
        count = 0
        
        if result + numbers[depth - 1] == target:
            count += 1
            
        if result - numbers[depth - 1] == target:
            count += 1
        
        return count
    
    x = dfs(n, numbers, target, depth + 1, result + numbers[depth - 1])
    y = dfs(n, numbers, target, depth + 1, result - numbers[depth - 1])
    
    return x + y

def solution(numbers, target):
    return dfs(len(numbers), numbers, target, 1, 0)