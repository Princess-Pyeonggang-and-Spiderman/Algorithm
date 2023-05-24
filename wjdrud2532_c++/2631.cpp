#include <iostream>
#include <algorithm>
<<<<<<< HEAD
#include <queue>

using namespace std;

int T, K;
=======

using namespace std;

int N, MaxLIS;
int arr[201], dp[201];
>>>>>>> origin/wjdrud2532

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

<<<<<<< HEAD
    cin >> T;

    while(T --)
    {
        cin >> K;

        priority_queue<long long int, vector<long long int>, greater<long long int> > pq;
        long long int result = 0;

        int tempnum;
        for(int i = 0; i < K; i ++)
        {
            cin >> tempnum;
            pq.push(tempnum);
        }

        long long int num1, num2;
        while(pq.size() > 1)
        {
            num1 = pq.top();
            pq.pop();

            num2 = pq.top();
            pq.pop();

            result += (num1 + num2);
            pq.push(num1 + num2);
        }

        cout << result << "\n";
    }
    return 0;
}
=======
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
>>>>>>> origin/wjdrud2532
