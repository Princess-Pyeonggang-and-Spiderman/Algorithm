#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N, M;
    int dp[1001][1001];

    cin >> N >> M;

    //bottom up
    //[i - 1][j - 1]   [i - 1][j]   [i][j - 1] 을 계산하기 위해 1부터 시작
    for(int i = 1; i <= N; i ++)
    {
        for(int j = 1; j <= M; j ++)
        {
            cin >> dp[i][j];
            dp[i][j] += max({dp[i - 1][j -1], dp[i - 1][j], dp[i][j - 1]});
        }
    }

    cout << dp[N][M] << "\n";

    return 0;
}


/*
 #include <iostream>
 #include <algorithm>
 #include <vector>

 using namespace std;

 int main()
 {
     cin.tie(nullptr);
     cout.tie(nullptr);
     ios_base::sync_with_stdio(false);

     int N = 0, M = 0;
    //이중 벡터
     vector<vector<int>> V_dp;
 
    //이중 벡터 생성을 위한 임시 int백터
     vector<int> tempV;
     
     int tempnum = 0;
     
     cin >> N >> M;
     
    //i = 0일 때 M길이를 갖는 vector를 추가
     tempV.resize(M);
 
     V_dp.push_back(tempV);
 
    //입력 1부터 받으므로 push_back 해야 하는 vector에 기본적으로 하나를 push 하기 위해 사용
    //
     tempV.resize(1);
     
     for(int i = 1; i <= N; i ++)
     {
         V_dp.push_back(tempV);
 
        //resize 안하고 이렇게 해도 됨
        //V_dp[i].push_back(0);
 
 
        //같은 방식
         for(int j = 1; j <= M; j ++)
         {
             cin >> tempnum;
             V_dp[i].push_back(tempnum);
             V_dp[i][j] += max({V_dp[i - 1][j - 1], V_dp[i - 1][j], V_dp[i][j - 1]});
         }
     }

     cout << V_dp[N][M] << "\n";

     return 0;
 }

 */
