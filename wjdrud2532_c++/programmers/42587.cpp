#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<pair<int, int>> q;
    
    int priorCnt[10] = {0, };   // 배열 크기 주의, 경고로 안알려줌
    int currentPrior = 9;
    
    for(int i = 0; i < priorities.size(); i ++) // 우선 순위 개수 카운트
    {
        priorCnt[priorities[i]] ++;
        q.push({priorities[i], i}); // queue에 모든 값 push
    }
    
    int tempnum = 1;
    
    while(!q.empty())       //우선순위 순서대로 q에서 pop
    {
        if(priorCnt[currentPrior] <= 0) // 현재 우선순위에 해당되는 값이 없다면 다음 우선순위로 넘어감
        {
            currentPrior --;
            continue;
        }
                
        if(q.front().first == currentPrior)     // 현재 우선순위에 해당될 경우 삭제
        {
            if(q.front().second == location)    //언제 확인해야 하는지 위치 주의
            {
                return tempnum;
            }
            
            q.pop();
            priorCnt[currentPrior] --;
            tempnum ++ ;
        }
        else  // 현재 우선순위가 아닌 경우 뒤로 넘김
        {
            q.push(q.front());
            q.pop();
        }
    }
    return 0;
}





