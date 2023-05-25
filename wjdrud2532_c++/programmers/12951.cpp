#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
        
    //A == 65   Z == 90
    //a == 97   z == 122'
    
    if('a' <= s[0] && s[0] <= 'z')
        s[0] -= 32;
    
    for(int i = 1; i < s.size(); i ++)
    {
        if(s[i - 1] == ' ') // 이전 문자가 공백이면 (== 현재 위치가 단어의 첫 글자라면)
        {
            if('a' <= s[i] && s[i] <= 'z')  // 대문자로 변경
                s[i] -= 32;
        }
        else
        {
            if('A' <= s[i] && s[i] <= 'Z')
                s[i] += 32;
        }
    }
    cout << s << "\n";
    answer = s;
    return answer;
    
    // 공백을 남겨뒤야함
}