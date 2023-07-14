from collections import deque

def solution(bridge_length, weight, truck_weights):
    # (무게, 시간)
    bridge = deque()
    q = deque(truck_weights)
    
    total, time = 0, 0
    
    while q:
        time += 1
        
        # 다리 건너기
        for i in range(len(bridge)):
            bridge[i][1] -= 1
        
        # 다리 지나기 완료 확인
        while bridge and bridge[0][1] == 0:
            total -= bridge[0][0]
            bridge.popleft()
        
        # 다리에 올리기
        truck = q[0]
        
        if len(bridge) < bridge_length and total + truck <= weight:
            bridge.append([truck, bridge_length])
            total += truck
            q.popleft()
        
    # 다리에 모두 올라가 있는 상태에서 마지막으로 올라간 truck 잔여 시간만큼 추가
    return time + bridge[-1][1]