def solution(cap, n, deliveries, pickups):
    distance = 0
    d_count, p_count = 0, 0
    
    for i in range(n - 1, -1, -1):
        # 50 개 이하이기 때문에 while 문 사용
        while deliveries[i] > d_count or pickups[i] > p_count:
            # 왕복하여 배달하는 횟수 반영
            d_count += cap
            p_count += cap
            distance += (i + 1) * 2
            
        # 배달, 수거 완료
        d_count -= deliveries[i]
        p_count -= pickups[i]
    
    return distance