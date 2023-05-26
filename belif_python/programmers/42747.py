def solution(citations):
    result = 0
    
    for i in range(max(citations) + 1):
        count = 0
        for j in range(len(citations)):
            if i <= citations[j]:
                count += 1
        
        if count >= i:
            result = max(result, i)
        
    return result