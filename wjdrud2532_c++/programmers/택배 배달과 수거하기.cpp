#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    int delLoca = deliveries.size() - 1;    // 탐색 시작 위치
    int picLoca = pickups.size() - 1;
    
    while(deliveries[delLoca] == 0 && pickups[picLoca] == 0)
    {
        delLoca --;
        picLoca --;
    }
    
    // cout << delLoca << " " << picLoca << "\n";
    
    while(delLoca >= 0 || picLoca >= 0)
    {
        int delLength = 0;         // 현재 길이
        int picLength = 0;
        
        int currentDelCap = 0;      // 현재 담아둔 용량
        int currentPicCap = 0;
        
        // 최대 용량을 채웠거나 0에 도달할 때 까지 반복
        
        // ======================================================       
        while(deliveries[delLoca] == 0) // 0 을 갖는 경우 이동
            delLoca --;

        delLength = delLoca;

        // 적재 가능하고 범위 안에 존재할 경우
        while(currentDelCap + deliveries[delLoca] <= cap && delLoca >= 0)
        {
            currentDelCap += deliveries[delLoca];
            delLoca --;
        }
        
        // currentDelCap < cap
        if(currentDelCap + deliveries[delLoca] > cap && delLoca >= 0) // 공간이 남는 경우
        {
            deliveries[delLoca] -= (cap - currentDelCap); 
            currentDelCap += (cap - currentDelCap);    // 담을 수 있는 만큼 담는다
        } 
        // ======================================================
        // ======================================================       
        while(pickups[picLoca] == 0) // 0 을 갖는 경우 이동
            picLoca --;

        picLength = picLoca;

        // 적재 가능하고 범위 안에 존재할 경우
        while(currentPicCap + pickups[picLoca] <= cap && picLoca >= 0)
        {
            currentPicCap += pickups[picLoca];
            picLoca --;
        }
        
        // currentDelCap < cap
        if(currentPicCap + pickups[picLoca] > cap && picLoca >= 0) // 공간이 남는 경우
        {
            pickups[picLoca] -= (cap - currentPicCap); 
            currentPicCap += (cap - currentPicCap);    // 담을 수 있는 만큼 담는다
        } 
        // ======================================================

        delLength ++;
        picLength ++;
        
        answer += max(delLength, picLength) * 2;
        // cout << delLength << "  " << picLength << "  answer = ";
        // cout << answer << "\n";
    }
    
    return answer;
}
