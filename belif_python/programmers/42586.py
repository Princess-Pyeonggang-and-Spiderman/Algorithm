from collections import deque

def solution(progresses, speeds):
    result = []
    
    # (진행률, 속도)
    q = deque()
    
    for i in range(len(speeds)):
        q.append([progresses[i], speeds[i]])
    
    while q:
        count = 0
        
        # 모든 진행률 속도만큼 update
        for s in q:
            s[0] += s[1]

        # 가능한 모든 것들 pop
        while q and q[0][0] >= 100:
            q.popleft()
            count += 1
        
        # pop 한 갯수만큼 결과에 추가
        if count != 0:
            result.append(count)
    
    return result