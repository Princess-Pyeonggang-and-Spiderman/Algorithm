from collections import deque

def solution(queue1, queue2):
    
    q1, q2 = deque(queue1), deque(queue2)
    total_length = len(queue1) + len(queue2) + 2
    sum1, sum2 = sum(q1), sum(q2)
    count = 0
    
    while sum1 != sum2:
        if count == total_length:
            return -1
        
        if sum1 > sum2:
            x = q1.popleft()
            sum1 -= x
            q2.append(x)
            sum2 += x
        elif sum1 < sum2:
            x = q2.popleft()
            sum2 -= x
            q1.append(x)
            sum1 += x
        
        count += 1
    
    return count