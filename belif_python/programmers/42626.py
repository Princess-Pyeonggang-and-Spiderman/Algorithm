import heapq

def solution(scoville, K):
    result = 0
    
    heapq.heapify(scoville)
    
    while scoville:
        # 가장 맵지 않은 음식의 스코빌 지수
        x = heapq.heappop(scoville)
        
        # 합칠 필요가 없다면 return result
        if x >= K:
            return result
        
        # 더 이상 합칠 것이 없다면 return -1
        if len(scoville) == 0:
            return -1
        
        # 두 번째로 맵지 않은 음식의 스코빌 지수
        y = heapq.heappop(scoville)
        
        # 합치기
        result += 1
        heapq.heappush(scoville, (x + y * 2))