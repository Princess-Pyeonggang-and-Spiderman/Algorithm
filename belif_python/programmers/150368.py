from itertools import product

def solution(users, emoticons):
    answer = []
    
    # int 형으로 변환
    for i in range(len(users)):
        users[i][0], users[i][1] = int(users[i][0]), int(users[i][1])
    for i in range(len(emoticons)):
        emoticons[i] = int(emoticons[i])
    
    # 할인율의 모든 경우의 수 계산
    off_list = list(product([10, 20, 30, 40], repeat=len(emoticons)))
    
    print(off_list)
    
    # 모든 할인율 경우의 수 만큼 반복
    for off in off_list:
        # 이모티콘 플러스 총 사용자 수
        emoticon_plus = 0
        # 이모티콘 총 구매 비용 - user
        user_cost = [0] * len(users)
        
        # 이모티콘 만큼 반복
        for i in range(len(emoticons)):
            # user 만큼 반복
            for j in range(len(users)):
                # user 할인율이 구매해도 될 정도라면
                if users[j][0] <= off[i]:
                    # 할인율 적용하여 구매 비용에 반영
                    user_cost[j] += (emoticons[i] * (100 - off[i])) // 100
        
        # 모든 유저에 대해 총 구매 비용이 이모티콘 플러스를 구매해도 될 정도라면
        # 이모티콘 플러스 총 사용자 수 + 1, 구매 비용 0 적용
        for i in range(len(users)):
            if users[i][1] <= user_cost[i]:
                emoticon_plus += 1
                user_cost[i] = 0
        
        # 모든 결과 리스트에 기록
        answer.append((emoticon_plus, sum(user_cost)))
    
    # 이모티콘 플러스 수, 이모티콘 구매 이력 순으로 정렬 - 둘 다 높은 순
    answer.sort(key=lambda x:(-x[0], -x[1]))
    
    return answer[0]