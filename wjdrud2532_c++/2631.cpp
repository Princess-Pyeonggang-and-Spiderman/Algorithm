#include <iostream>
#include <algorithm>

using namespace std;

int N, MaxLIS;
int arr[201], dp[201];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 1; i <= N; i ++)
    {
        cin >> arr[i];
        dp[i] = 1;
    }

    for(int i = 1; i <= N; i ++)
    {
        for(int j = i; j >= 1; j --)
        {
            if(arr[i] > arr[j] && dp[j] >= dp[i] - 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
        if(dp[i] > MaxLIS)
            MaxLIS = dp[i];
    }

    cout << N - MaxLIS << "\n";

    return 0;
}