def solution(arr):
    result = [arr[0]]
    
    pre = arr[0]
    
    for num in arr:
        # 이전 것과 같다면 무시, 같지 않다면 추가
        if pre != num:
            result.append(num)
            pre = num
            
    return result