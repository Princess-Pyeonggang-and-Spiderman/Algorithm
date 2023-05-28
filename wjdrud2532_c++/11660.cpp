#include <iostream>
#include <queue>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int dp[1025][1025];
    
    int N, M;
    int startN, startM, endN, endM;
    
    cin >> N >> M;
    
    int tempnum;
    
    for(int i = 1; i <= N; i ++)
    {
        for(int j = 1; j <= N; j ++)
        {
            cin >> tempnum;

            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + tempnum;

        }
    }
    
    while(M --)
    {
        cin >> startN >> startM >> endN >> endM;
        
        cout << dp[endN][endM] - dp[startN - 1][endM] - dp[endN][startM - 1] + dp[startN - 1][startM - 1] << "\n";
    }
    

    return 0;
}
