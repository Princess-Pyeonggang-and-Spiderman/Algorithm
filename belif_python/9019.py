from collections import deque

def getDSLR(x):
    dslr = []
    
    # DSLR
    dslr.append((x * 2) % 10000)
    dslr.append(x - 1 if x != 0 else 9999)
    dslr.append((x * 10) % 10000 + (x * 10) // 10000)
    dslr.append((x % 10) * 10000 // 10 + (x // 10))

    return dslr

def main():
    t = int(input())

    # DSLR 문자
    dslr_str = ["D", "S", "L", "R"]

    for _ in range(t):
        a, b = map(int, input().split())

        # bfs 사용 : visited, deque 설정
        visited = [False] * (10001)
        q = deque()
        visited[a] = True
        q.append((a, []))

        while q:
            a, results = q.popleft()
            
            if a == b:
                print(''.join(results))
                break
            
            dslr = getDSLR(a)

            for i in range(len(dslr)):
                if not visited[dslr[i]]:
                    visited[dslr[i]] = True
                    q.append((dslr[i], results + [dslr_str[i]]))

if __name__ == "__main__":
    main()