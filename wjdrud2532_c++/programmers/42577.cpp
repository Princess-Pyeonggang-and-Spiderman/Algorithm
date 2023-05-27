#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    map<string, int> m;
    
    int maxlength = 0;
    int minlength = 1000001;
    
    for(int i = 0; i < phone_book.size(); i ++)
    {
        if(phone_book[i].size() > maxlength)
            maxlength = phone_book[i].size();
        
        if(phone_book[i].size() < minlength)
            minlength = phone_book[i].size();
        
        m.insert({phone_book[i], 1});
    }    
    //min 부터 max 까지의 잘라서 map에 추가. 추가할 필요 없음 그냥 확인만
    // map에 이미 값이 존재한다면 return false
    //
    
    for(int i = 0; i < phone_book.size(); i ++)
    {
        string tempstr = "";
            
        for(int j = 0; j < minlength; j ++)
        {
            tempstr += phone_book[i][j];
        }
        
        for(int j = minlength; (j <= maxlength && j < phone_book[i].size()); j ++)
        {
            if(m.find(tempstr) != m.end())
                return false;
            
            tempstr += phone_book[i][j];
        }
    }
    
    return answer;
}

/*
#include <string>
#include <vector>

using namespace std;

int minlength = 1000001;

bool cmpstring(string s1, string s2)
{
    int strlength = s1.size() > s2.size() ? s2.size() : s1.size();
    
    for(int i = 0; i < strlength; i ++)
    {
        if(s1[i] != s2[i])
            return false;
    }
    
    return true;
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    for(int i = 0; i < phone_book.size(); i ++)
    {
        for(int j = i + 1; j < phone_book.size(); j ++)
        {          
            // 한 번호가 다른 번호의 접두어인 경우
            if(cmpstring(phone_book[i], phone_book[j]) == true)
            {
                return false;
            }
        }
    }
    
    return true;
}
*/