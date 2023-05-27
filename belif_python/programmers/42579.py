def solution(genres, plays):
    result = []
    
    # key : 장르, value : [횟수, 고유번호]
    dict_genres = {}
    # 장르의 종류
    set_genres = list(set(genres))
    # 장르마다 노래 재생 횟수 합
    total_genres = {}
    
    # hash-map 에 장르끼리 모으기, 장르마다 노래 재생 횟수 합 구하기
    for i in range(len(genres)):
        if not genres[i] in dict_genres:
            dict_genres[genres[i]] = []
            total_genres[genres[i]] = 0
            
        dict_genres[genres[i]].append([plays[i], i])
        total_genres[genres[i]] += plays[i]
    
    # 장르 노래 재생 횟수 기준 정렬 - 내림차순
    set_genres.sort(key=lambda x: -total_genres[x])
    
    for i in range(len(set_genres)):
        dict_genres[set_genres[i]].sort(key=lambda x: (-x[0], x[1]))
        
        for j in range(len(dict_genres[set_genres[i]])):
            result.append(dict_genres[set_genres[i]][j][1])
            if j == 1:
                break
            
    return result
        