#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> tempv;
    for(int i = 0; i < numbers.size(); i ++)
    {
        tempv.push_back(to_string(numbers[i]));
    }
    
    // 두 문자열을 합친 후 큰 순서대로 비교
    sort(tempv.begin(), tempv.end(), cmp);
    
    // 이어붙힘
    for(int i = 0; i < tempv.size(); i ++)
    {
        answer += tempv[i];
    }
    
    // "000" 을 방지
    if(answer[0] == '0')
        return "0";
    
    return answer;
}