#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    int arr[31] = {0, };
    arr[0] = 50;
    
    
    
    // 여분이 있는 경우
    for(int i = 0; i < reserve.size(); i ++)
    {
        arr[reserve[i]] = 1;
    }
    
    // 잃어버린 경우
    for(int i = 0; i < lost.size(); i ++)
    {
        arr[lost[i]] --;
    }
    
    for(int i = 1; i <= n; i ++)
    {
        if(arr[i] == 0 || arr[i] == 1) // 체육복 가지고 있을 경우
        {
            answer ++;
            continue;
        }
        
        if(arr[i] == -1)    // 도둑맞은 경우
        {
            if(arr[i - 1] == 1) // 앞 사람에게 여분이 있을 경우
            {
                answer ++;
            }
            else if(arr[i + 1] == 1)    // 뒷 사람에게 여분이 있을 경우
            {
                answer ++;
                arr[i + 1] = 0;
            }
        }
        
    }
    return answer;
}

/*
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    
    전체 N에서
        lost의 앞 뒤로 여벌이 있는지 확인
            빌릴 수 있는 경우가 앞, 뒤 2가지 경우라면 앞의 것을 빌림
    
    
    int pe[31] = {0, };
    pe[0] = 5;
    
    for(int i = 0; i < lost.size(); i ++)
    {
        pe[lost[i]] = 2;    // 잃어버린 경우 2로 표시
    }
    
    for(int i = 0; i < reserve.size(); i ++)
    {
        pe[reserve[i]] = 1; // 여벌 존재하는 경우 1로 표시
    }
    
    for(int i = 1; i <= n; i ++)
    {
        cout << pe[i] << " ";
    }
    
    for(int i = 1; i <= n ; i++) // 학생 수만큼 탐색
    {
        if(pe[i] != 2) 
        {
            answer ++;
        }
        
        if(pe[i] == 1)          // 현재 학생이 여벌이 있는 경우 경우
        {
            if(pe[i - 1] == 2)  // 앞의 학생이 도둑맞은 경우 빌려줌
            {
                pe[i - 1] = 0;
                pe[i] = 0;
                answer ++;
            }
            else if(pe[i + 1] == 2)  // 뒤의 학생이 도둑맞은 경우
            {
                pe[i + 1] = 0;
                pe[i] = 0;
            }
        }
    }
    
    return answer;
}


*/