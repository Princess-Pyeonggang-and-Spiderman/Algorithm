def solution(s):
    isUpper = True
    
    string = list(s)
    
    for i in range(len(string)):
        if string[i] == " ":
            isUpper = True
            continue
        
        if isUpper:
            string[i] = string[i].upper()
            isUpper = False
        else:
            string[i] = string[i].lower()
            
    return ''.join(string)