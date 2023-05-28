from itertools import combinations

def solution(clothes):
    dict_cloth = {}
    
    for cloth in clothes:
        if not cloth[1] in dict_cloth:
            # 옷을 안입었을 경우도 1개의 경우의 수로 가정 -> 초기값 2
            dict_cloth[cloth[1]] = 2
        else:
            dict_cloth[cloth[1]] += 1
    
    result = 1
    for value in dict_cloth.values():
        result *= value
    
    # 옷을 아예 안입은 경우는 없기 때문에 -1
    return result - 1
    
    
    
    # 아래 경우로 하게 되면 테스트 케이스 1 통과 못함 (30 C 1, 30 C 2... 진행해야 하기 때문)
     
    # n = len(dict_cloth)
    # count = 0

    # for r in range(1, n + 1):
        # comb_list = list(combinations(dict_cloth, r))
        
        # for comb in comb_list:
          #   x = 1
            # for classification in comb:
              #   x *= dict_cloth[classification]
            # count += x
        
    # return count