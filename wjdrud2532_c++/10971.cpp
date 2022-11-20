#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N, MinValue = INT_MAX, sum = 0;
int arr[11][11] = {0, };
bool IsVisit[11] = {0, };

void CalcSumDfs(int CurrentPoint, int StartPoint, int cnt, int value)
{
    //다시 돌아와야 하는 경우
    //돌아갈 수 있는지 확인
    if(cnt == N && arr[CurrentPoint][StartPoint] > 0)
    {
        value += arr[CurrentPoint][StartPoint];
        
        //최소값 비교
        if(value < MinValue)
            MinValue = value;
        
        return ;
    }
    
    for(int j = 1; j <= N; j ++)
    {
        //방문 및 이동 가능 여부 확인
        if(IsVisit[j] == false && arr[CurrentPoint][j] != 0)
        {
            IsVisit[j] = true;
            //value += arr[CurrentPoint][j]; 와
            //CalcSumDfs(j, StartPoint, cnt + 1, value + arr[CurrentPoint][j]);
            //의 결과가 다름
            // ++cnt 와 cnt + 1 또한 마찬가지
            CalcSumDfs(j, StartPoint, cnt + 1, value);
            IsVisit[j] = false;
        }
    }
    return ;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    //전부 입력 받음
    for(int i = 1; i <= N; i ++)
    {
        for(int j = 1; j <= N; j ++)
        {
            cin >> arr[i][j];
        }
    }
    
    // 첫 번째 도시부터 시작
    for(int i = 1; i <= N; i ++)
    {
        //방문 설정
        IsVisit[i] = true;
        CalcSumDfs(i, i, 1, 0);
        IsVisit[i] = false;
    }
    cout << MinValue << "\n";
}

