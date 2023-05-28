#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    /*
    각 progresses의 완성 날짜를 계산
    
    max(이전 progresses의 완료 날짜, 현재 progresses의 완료 날짜) 
    
    최초 설정 배포날짜는 progresses 의 크기
    이전 완료 날짜가 더 크다면 배포 날짜 --
    아니라면 넘어감
    */
    
    
    /*
    stack
    
    완료날짜와 index를 같이 push
    스택에서 꺼낼 때 비교하면서 이전의 값이 현재보다 크다면 cnt++ 아니라면 cnt 초기화
    하는 방식으로 
    */
    
    pair<int, int> p;
    stack<pair<int, int>> s;
    vector<int> tempv;
    for(int i = 0; i < progresses.size(); i ++)
    {
        //완료 날짜 계산
        int complete = 100 - progresses[i]; // 100 - 93 = 7
        int mod =  complete % speeds[i];    // 나머지계산
        
        complete /= speeds[i];              // 7 / 1
        if(mod != 0)
            complete ++;                    // 나머지 있는 경우 완료 날짜 ++;
        //complete 는 7 -> 7일에 작업이 완료됨
        
        tempv.push_back(complete);
        
        //s.push({i, complete})
        
    }
    
    // for(int i = 0; i < tempv.size(); i ++)
    // {
    //     cout << tempv[i] << " ";
    // }
    
    int cnt = 1;
    int date = tempv[0];   // 지난 날짜
    for(int i = 1; i < tempv.size(); i ++)
    {
        if(tempv[i] <= date)
        {
            cnt ++;
        }
        else
        {
            answer.push_back(cnt);
            date = tempv[i];
            // += 하면 틀림
            cnt = 1;
        }
    }
    answer.push_back(cnt);
    
    return answer;
}