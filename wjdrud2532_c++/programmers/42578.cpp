#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    // 총 개수만 알아내어 조합 공식을 적용하면 될 듯
    map<string, int> m;
    
    for(int i = 0; i < clothes.size(); i ++)
    {
        auto it = m.find(clothes[i][1]);
            
        if(it == m.end())   // 없으면 추가
        {
            m.insert({clothes[i][1], 1});
        }
        else                // 있으면 ++
        {
            m.at(it->first) = it->second + 1;
        }
    }
    
    // for(auto it = m.begin(); it != m.end(); it ++)
    // {
    //     cout << it->first << " " << it->second << "\n";
    // }
    
    
    
    /*      
    a = 1
    b = 2
    c = 3 이라 할 때
    정답은
    1 + 2 + 3
            + 1 * 2
            + 2 * 3
            + 1 * 3
                + 1 * 2 * 3
    즉, m의 각 개수에 대한 순열 곱셈
    */
    
    cout << m.size();
    
    // m의 .size만큼 
//     for(int i = 0; i < m.size(); i ++)
//     {
        
//     }
    
    
    //입지 않은 경우 추가로 + 1 해야함
    
    for(auto it = m.begin(); it != m.end(); it ++)
    {
        answer *= (it->second + 1);     
        cout << answer << "\n";
    }
    
    // 모두 입지 않은 경우를 제외
    answer --;
    return answer;
}