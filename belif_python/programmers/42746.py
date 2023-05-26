from functools import cmp_to_key

def custom_cmp(x, y):
    str_x, str_y = str(x), str(y)
    
    x_v = int(str_x + str_y)
    y_v = int(str_y + str_x)
    
    if x_v > y_v:
        return -1
    elif x_v < y_v:
        return 1
    else:
        return 0
            

def solution(numbers):
    numbers.sort(key=cmp_to_key(custom_cmp))
    
    return str(int(''.join(map(str, numbers))))