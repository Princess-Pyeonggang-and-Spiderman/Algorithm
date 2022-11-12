#include <iostream>

using namespace std;

int main()
{

    int n;
    cin >> n;

    //초기값 설정
    long long dp[1001] = {1, 1, 2, };

    
    for (int i = 3; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;

    cout << dp[n] << "\n ";

    return 0;
}
