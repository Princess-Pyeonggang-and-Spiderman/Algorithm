def solution(s):
    left_count = 0
    
    for i in range(len(s)):
        if s[i] == "(":
            left_count += 1
        else:
            if left_count <= 0:
                return False
            left_count -= 1
            
    if left_count == 0:
        return True
    else:
        return False