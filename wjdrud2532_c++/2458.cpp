#include <iostream>
#include <algorithm>
#include <climits>

//플로이드 워셜 3중 for문 O(N^3)

//  INT_MAX로 하면 음수값이 나와서 오류남
//  아마 floyd[i][k] + floyd[k][j]하는 과정에서 오버플로우로 음수값이 나와 제대로 동작하지 않는 것 같음
//  INT_MAX/2 - 2 로 하면 정상작동함
//  근데 확인하기 어려우니까 1000000 으로 설정
#define INF 1000000

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    int floyd[501][501];

    cin >> N >> M;

    //어느 부분에 값이 들어갔는지 확인하기 위해 전부 INF로 초기화
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            //모든 경로에 대해 갈 수 없다고 설정해두고 시작
            floyd[i][j] = INF;
        }
    }

    int small, tall;
    for (int i = 1; i <= M; i++)
    {
        cin >> small >> tall;

        //연결되어 있을 경우 1로 재설정
        floyd[small][tall] = 1;
    }

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                //floyd 과정을 통해 현재 i로 시작하여 도달할 수 있는 있는 모든 지점을 알 수 있다
                //이전 값은 알 수 없다
                floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cout << floyd[i][j] << " ";
        }
        cout << "\n";
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        int tempcnt = 0;
        for (int j = 1; j <= N; j++)
        {
            //  모든 지점을 돌면서 확인

            //  현재 i에서 연결된 사람이 있다면(서로 키를 비교할 수 있다면)
            if (floyd[i][j] != INF || floyd[j][i] != INF)
            {
                //연결 카운트 + 1
                tempcnt ++;
            }
        }
        //  즉, 어떤 지점으로부터 i에 도달할 수 있는 값들 + i에서 출발하여 도달할 수 있는 값들
        if (tempcnt == N - 1) //모두와 비교할 수 있는 경우
            cnt ++;
    }
    cout << cnt << "\n";
}
