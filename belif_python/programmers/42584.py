def solution(prices):
    result = []
    
    for i in range(len(prices)):
        count = 0
        # 찾은 것이 있는지 여부
        isTrue = True
    
        # 완전탐색으로 i + 1 ~ 끝까지 반복하여 가격이 떨어진 부분 찾기
        for j in range(i + 1, len(prices)):
            if prices[i] > prices[j]:
                count = j - i
                isTrue = False
                break
        
        if isTrue:
            result.append(len(prices) - 1 - i)
        else:
            result.append(count)
        
    return result