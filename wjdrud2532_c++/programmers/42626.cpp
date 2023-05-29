#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < scoville.size(); i ++)
    {
        pq.push(scoville[i]);
    }
    
    while(pq.size() > 1)
    {
        if(pq.top() >= K)
            break;
        
        int num1 = pq.top();
        pq.pop();
        int num2 = pq.top();
        pq.pop();
        
        int tempK = num1 + (num2 * 2);
        pq.push(tempK);
        
        answer ++;
    }
    
    if(pq.top() < K)
        return -1;
    
    return answer;
}