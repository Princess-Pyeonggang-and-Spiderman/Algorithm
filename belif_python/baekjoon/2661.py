# string 에 add_char 를 추가할 수 있는지 확인
def check(string, add_char):
    # 뒤에서부터 slice 하여 확인
    for i in range(len(string)):
        # 비교할 첫 번째 문자열 (뒤에서부터 slice)
        current_string = string[len(string) - i:] + add_char

        # 다음으로 비교할 문자열이 없으면 모든 경우를 통과하였으므로 return True
        if len(string) - i - len(current_string) < 0:
            return True

        # 비교할 두 번째 문자열 (처음 자른 문자열 만큼 추가로 자르기)
        compare_string = string[len(string) - i - len(current_string):len(string) - i]

        # '나쁜 수열' 일 경우 return False
        if current_string == compare_string:
            return False

    return True

# 백트래킹을 위한 dfs
def dfs(string):
    # 문자열 완성 시 시스템 종료
    if len(string) == n:
        print(string)
        exit(0)
    
    # 1, 2, 3 에 대해서 추가
    x1, x2, x3 = "", "", ""

    if check(string, "1"):
        x1 = dfs(string + "1")
    
    if check(string, "2"):
        x2 = dfs(string + "2")
    
    if check(string, "3"):
        x3 = dfs(string + "3")

    # 1, 2, 3 에 대해서 추가하였을 경우와 안했을 경우를 모두 판단하여 return
    if x1 != "" and x2 != "" and x3 != "":
        return min(x1, x2, x3)
    elif x1 != "" and x2 != "" and x3 == "":
        return min(x1, x2)
    elif x1 != "" and x2 == "" and x3 != "":
        return min(x1, x3)
    elif x1 == "" and x2 != "" and x3 != "":
        return min(x2, x3)
    elif x1 == "" and x2 == "" and x3 != "":
        return x3
    elif x1 == "" and x2 != "" and x3 == "":
        return x2
    elif x1 != "" and x2 == "" and x3 == "":
        return x1
    else:
        return ""

INF = int(1e9)
n = int(input())

print(dfs(""))