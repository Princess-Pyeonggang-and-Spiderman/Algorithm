#include <iostream>

using namespace std;

int N, MaxValue;
int dx[] = {0, 0, - 1, 1};
int dy[] = {- 1, 1, 0, 0};
int arr[501][501] = {0,};
int dp[501][501] = {0,};
//int IsVisit[501][501] = {0,};

int dfsDP(int x, int y)
{
    // 방문한 적이 있다면 해당 위치에서 이동할 수 있는 최대값이 저장되어 있으므로 그것을 반환
    if (dp[x][y] != 0)
        return dp[x][y];

    // 방문 표시
    dp[x][y] = 1;

    for (int dir = 0; dir < 4; dir ++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        // 범위 밖인 경우 넘어감
        if (nx < 0 || ny < 0 || nx >= N || ny >= N)
            continue;

        // 해당 위치의 값이 현재 값보다 작다면 넘어감 ㅜ
        if (arr[x][y] >= arr[nx][ny])
            continue;

        // 4방향 탐색, 이동할 수 있다면 ++
        dp[x][y] = max(dp[x][y], dfsDP(nx, ny) + 1);
    }

    return dp[x][y];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i ++)
        for (int j = 0; j < N; j ++)
            cin >> arr[i][j];

    for (int i = 0; i < N; i ++)
        for (int j = 0; j < N; j ++)
            MaxValue = max(MaxValue, dfsDP(i, j));

//    for (int i = 0; i < N; i ++)
//    {
//        for (int j = 0; j < N; j ++)
//            cout << dp[i][j] << " ";
//        cout << "\n";
//    }

    cout << MaxValue << "\n";

    return 0;
}