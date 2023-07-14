def solution(today, terms, privacies):
    answer = []
    
    # 오늘 날짜를 연, 월, 일로 분리하여 int 형으로 저장
    today_year, today_month, today_day = map(int, today.split("."))
    terms_dict = {}
    
    for term in terms:
        t1, t2 = term.split(" ")
        terms_dict[t1] = int(t2)
        
    for i in range(len(privacies)):
        # 날짜와 타입 분리
        date, type = privacies[i].split(" ")
        
        # 날짜를 연, 월, 일로 분리하고 int형으로 저장
        year, month, day = map(int, date.split("."))
        
        # terms 반영 -> 해당 개인정보 저장 날짜 + 보관 기간
        month += terms_dict[type]
        year += month // 12
        month %= 12
        
        # 12월일 때, 연도가 1 증가하고 월이 0 으로 되어버리는 예외 처리
        if month == 0:
            month = 12
            year -= 1
        
        # 연도, 월, 일 순으로 비교 -> 날짜가 지났다면 결과에 저장
        if today_year > year:
            answer.append(i + 1)
        elif today_year == year:
            if today_month > month or (today_month == month and today_day >= day):
                answer.append(i + 1)
    
    return answer