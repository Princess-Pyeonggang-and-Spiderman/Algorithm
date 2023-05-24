import heapq

t = int(input())

for _ in range(t):
    n = int(input())

    # 최소 우선순위 큐와 최대 우선순위 큐
    min_q = []
    max_q = []

    # insert 된 값들의 정보를 저장할 dictionary
    count = {}

    for _ in range(n):
        a, b = map(str, input().split())

        if a == "I":
            # INSERT : min, max q에 값을 넣어주고, count에 정보 반영
            heapq.heappush(min_q, int(b))
            heapq.heappush(max_q, -int(b))
            if b in count:
                count[b] += 1
            else:
                count[b] = 1
        elif b == "-1":
            # DELETE 최솟값 : min q에 값이 존재한다면 pop, count에 개수 차감 반영
            # 이미 남은 개수가 0개라면 q에서 다시 pop, 남은 개수가 1개 이상이라면 원래숫자-1 반영
            while True:
                if len(min_q) == 0:
                    break
                x = str(heapq.heappop(min_q))
                if count[x] == 0:
                    continue
                else:
                    count[x] -= 1
                    break                
        else:
            # DELTE 최댓값 : 최솟값과 똑같은 방법으로 진행
            while True:
                if len(max_q) == 0:
                    break
                x = str(-heapq.heappop(max_q))
                if count[x] == 0:
                    continue
                else:
                    count[x] -= 1
                    break


    # 결과값을 저장할 list
    results = []

    # min q에 남은 값 중 최솟값을 찾아서 results append (count 반영 포함)
    while True:
        if len(min_q) == 0:
            break
        a = str(heapq.heappop(min_q))
        if count[a] == 0:
            continue
        else:
            count[a] -= 1
            results.append(a)
            break

    # max q에 남은 값 중 최대값을 찾아서 results append (count 반영 포함)
    while True:
        if len(max_q) == 0:
            break
        b = str(-heapq.heappop(max_q))
        if count[b] == 0:
            continue
        else:
            count[b] -= 1
            results.append(b)
            break
    
    # results에 값이 없다면 "EMPTY" 출력, 값이 있다면 있는 값 출력
    if len(results) == 0:
        print("EMPTY")
    elif len(results) == 1:
        # ** 값이 하나라면 최소값과 최대값이 동일하기 때문에 두 번 출력
        print(results[0], results[0])
    else:
        print(results[1], results[0])