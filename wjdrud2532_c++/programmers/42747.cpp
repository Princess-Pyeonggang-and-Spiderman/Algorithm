#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    //내림차순 정렬
    sort(citations.begin(), citations.end(), greater<int>());
    
    for(int i = 0; i < citations.size(); i ++)
    {
        cout << citations[i] << " ";
        if(citations[i] > i)
            answer ++;
        else
            break;
    }
    
    return answer;
}