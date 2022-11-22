#include <iostream>

using namespace std;

int N, MaxValue = 0, tempValue = 0;
pair<int, int> p[15];

void recursion(int CurrentN, int value)
{
    //현재 위치의 value를 더함
    value += p[CurrentN].second;
    
    //현재 위치의 작업이 완료된 이후 날부터 탐색 시작
    for(int i = CurrentN + p[CurrentN].first; ; i ++)
    {
        //범위를 벗어나는 경우 중지
        if(i >= N)
            break;
        
        //다음 수행할 작업을 끝마칠 수 있는 경우 재귀탐색 시작
        if(p[i].first <= N - i)
            recursion(i, value);
    }
    
    if(value > MaxValue)
        MaxValue = value;
    
    return ;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;
    
    //input
    for(int i = 0; i < N; i ++)
    {
        cin >> p[i].first >> p[i].second;
    }
    
    MaxValue = 0;
    for(int i = 0; i < N; i ++)
    {
        //0부터 재귀탐색 시작
        if(p[i].first <= N - i)
        {
            recursion(i, 0);
        }
    }
    
    cout << MaxValue << " ";
}
