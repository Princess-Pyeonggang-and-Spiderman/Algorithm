from collections import deque

def solution(priorities, location):
    result = 0
    
    prior_count = [0] * 10
    now_prior = 0
    
    # (우선순위, idx)
    q = deque()
    
    for i in range(len(priorities)):
        q.append((priorities[i], i))
        
        # 우선순위가 몇 개 있는지 count
        prior_count[priorities[i]] += 1
        
        # 현재 가장 높은 우선순위 확인
        now_prior = max(now_prior, priorities[i])
    
    while q:
        prior, idx = q.popleft()
        
        if prior == now_prior:
            # 현재 우선순위와 같다면 pop 유지
            result += 1
            
            # 정답일 경우 return
            if idx == location:
                return result
            
            # 현재 우선순위 update
            prior_count[now_prior] -= 1
            while prior_count[now_prior] == 0:
                now_prior -= 1
        else:
            # 현재 우선순위와 다르다면 다시 push
            q.append((prior, idx))    
                