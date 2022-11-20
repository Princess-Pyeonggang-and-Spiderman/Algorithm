#include <iostream>

#include <queue>
#include <stack>

using namespace std;
int arr[501][501] = {0, };
bool IsVisit[501][501] {0, };
int MaxValue = -1;

void input(int N, int M)
{
    for(int i = 0; i < N; i ++)
        for(int j = 0; j < M; j ++)
            cin >> arr[i][j];
    return;
}


void UpDownLeftRight(int CurrentN, int CurrentM, int value, int cnt, int LimitN, int LimitM, int previousN, int previousM);
void SearchMax(int CurrentN, int CurrentM, int value, int cnt, int LimitN, int LimitM, int previousN, int previousM);

void SearchMax(int CurrentN, int CurrentM, int value, int cnt, int LimitN, int LimitM, int previousN, int previousM)
{
    
    value += arr[CurrentN][CurrentM];
    
    if(cnt == 2)
        UpDownLeftRight(previousN, previousM, value, cnt + 1, LimitN, LimitM, 0, 0);
    
    if(cnt == 3)
    {
        if(value > MaxValue)
            MaxValue = value;
        return;
    }
    
    cnt ++;
    UpDownLeftRight(CurrentN, CurrentM, value, cnt, LimitN, LimitM, 0, 0);
    
    return;
}

void UpDownLeftRight(int CurrentN, int CurrentM, int value, int cnt, int LimitN, int LimitM, int previousN, int previousM)
{
    if(CurrentN - 1 >= 0)
        if(!IsVisit[CurrentN - 1][CurrentM])
        {
            IsVisit[CurrentN - 1][CurrentM] = true;
            SearchMax(CurrentN - 1, CurrentM, value, cnt, LimitN, LimitM, CurrentN, CurrentM);
            IsVisit[CurrentN - 1][CurrentM] = false;
        }
    
    if(CurrentN + 1 < LimitN)
        if(!IsVisit[CurrentN + 1][CurrentM])
        {
            IsVisit[CurrentN + 1][CurrentM] = true;
            SearchMax(CurrentN + 1, CurrentM, value, cnt, LimitN, LimitM, CurrentN, CurrentM);
            IsVisit[CurrentN + 1][CurrentM] = false;
        }
    
    if(CurrentM - 1 >= 0)
        if(!IsVisit[CurrentN][CurrentM - 1])
        {
            IsVisit[CurrentN][CurrentM - 1] = true;
            SearchMax(CurrentN, CurrentM - 1, value, cnt, LimitN, LimitM, CurrentN, CurrentM);
            IsVisit[CurrentN][CurrentM - 1] = false;
        }

    if(CurrentM + 1 < LimitM)
        if(!IsVisit[CurrentN][CurrentM + 1])
        {
            IsVisit[CurrentN][CurrentM + 1] = true;
            SearchMax(CurrentN, CurrentM + 1, value, cnt, LimitN, LimitM, CurrentN, CurrentM);
            IsVisit[CurrentN][CurrentM + 1] = false;
        }

    return ;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    
    input(N, M);
    
    for(int i = 0; i < N; i ++)
    {
        for(int j = 0; j < M; j ++)
        {
            IsVisit[i][j] = true;
            SearchMax(i, j, 0, 0, N, M, 0, 0);
            IsVisit[i][j] = false;
        }
    }
    cout << MaxValue << endl;
    
}
