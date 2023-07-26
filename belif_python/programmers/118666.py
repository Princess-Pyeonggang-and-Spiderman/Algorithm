def solution(survey, choices):
    type = {"R" : 0, "T" : 0, "C" : 0, "F" : 0, "J" : 0, "M" : 0, "A" : 0, "N" : 0}
    
    for i in range(len(choices)):
        if choices[i] == 4:
            continue
        
        target = survey[i][0] if choices[i] < 4 else survey[i][1]
        type[target] += abs(4 - choices[i])
        
    answer = ""
    answer += "R" if type["R"] >= type["T"] else "T"
    answer += "C" if type["C"] >= type["F"] else "F"
    answer += "J" if type["J"] >= type["M"] else "M"
    answer += "A" if type["A"] >= type["N"] else "N"
    
    return answer