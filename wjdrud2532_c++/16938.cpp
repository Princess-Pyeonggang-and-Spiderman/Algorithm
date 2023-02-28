#include <iostream>
#include <algorithm>

using namespace std;

int N;
long long int L, R, X;
long long int arr[16];
bool IsVisit[16];
int result = 0;

void dfs(int current, long long int sum, int start)
{
    // 현재값 추가
    sum += arr[current];

    // 합이 최대를 넘으면 종료
    if(sum > R)
        return;

    // 합이 범위 안에 해당된다면
    if(L <= sum && sum <= R)
    {
        // 방문한 것들 중에서 min max 를 찾는다
        long long int MinValue = 100000000, MaxValue = -1;
        for(int i = start; i < N; i ++)
        {
            if(IsVisit[i])
            {
                if(arr[i] < MinValue)
                    MinValue = arr[i];

                if(arr[i] > MaxValue)
                    MaxValue = arr[i];
            }
        }

        // 정답에 해당되면 ++
        if((MaxValue - MinValue) >= X)
        {
            result ++;
        }
    }

    for(int i = current + 1; i < N; i ++)
    {
        if(!IsVisit[i])
        {
            IsVisit[i] = true;
            dfs(i, sum, start);
            IsVisit[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L >> R >> X;

    for(int i = 0; i < N; i ++)
    {
        cin >> arr[i];
    }

    //굳이 필요 없음
    //sort(arr, arr + N);

    for(int i = 0; i < N; i ++)
    {
        IsVisit[i] = true;
        dfs(i, 0, i);
    }

    cout << result << "\n";

    return 0;
}