def solution(phone_book):
    dict_phone = {}
    
    phone_book.sort(key=lambda x: len(x))
    
    for phone in phone_book:
        start_number = ""
        
        for number in phone:
            start_number += number
            if start_number in dict_phone:
                return False
            
        dict_phone[phone] = True
    
    return True