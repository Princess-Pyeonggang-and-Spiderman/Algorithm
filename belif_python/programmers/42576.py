def solution(participant, completion):
    part = {}
    
    for com in completion:
        if not com in part:
            part[com] = 1
        else:
            part[com] += 1
    
    for p in participant:
        if not p in part:
            return p
        
        if part[p] == 0:
            return p
        
        part[p] -= 1