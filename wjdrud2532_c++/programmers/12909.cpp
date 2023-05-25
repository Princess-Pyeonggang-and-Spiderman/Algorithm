#include<string>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool solution(string s)
{
    bool answer = true;
        
    if(s[0] == ')' || s[s.size() - 1] == '(')
        return false;
    
    int open = 0;
    int close = 0;
    
    int cnt = 0;
    
    for(int i = 0; i < s.size(); i ++)
    {
        if(s[i] == '(')
        {
            open ++;
            cnt ++;
        }
        else    // )
        {
            close ++;
            cnt --;
            if(cnt < 0)
                return false;
        }
    }
    
    if(open == close)
        return true;
    else
        return false;
    
    return answer;
}