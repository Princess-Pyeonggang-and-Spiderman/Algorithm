#include <iostream>
#include <algorithm>

using namespace std;

// pair .second 기준으로 오름차순 정렬
//bool comp(const pair<int, float>& a, const pair<int, float>& b)
//{
//    if(a.second == b.second)
//        return a.first < b.second;
//    return a.second < b.second;
//}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1)
    {
        int N, M;
        float tempM;

        cin >> N >> tempM;

        if(N == 0 && tempM == 0)
            break;

        pair<int, int> p[5001];
        int dp[10001] = {0, };
        int result = 0;

        // 소수점 int 형변환
        M = tempM * 100 + 0.5;

        for(int i = 0; i < N; i ++)
        {
            int price;
            cin >> price >> tempM;

            p[i].first = price;
            p[i].second = tempM * 100 + 0.5;
        }

        // 정렬 필요 없음
        //sort(p, p + N, comp);

        for(int i = 0; i < N; i ++)
        {
            //      0.01 ~ M
            for(int j = 1; j <= M; j ++)
            {
                // p[i]를 구매할 수 있는 경우
                if(j - p[i].second >= 0)
                {
                    //      현재값과     이전 값 + p[i].second를 구매한 값 중 더 큰 값
                    dp[j] = max(dp[j], dp[j - p[i].second] + p[i].first);
                }
            }
        }
        cout << dp[M] << "\n";
    }
    return 0;
}