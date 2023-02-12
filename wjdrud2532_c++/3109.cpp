#include <iostream>
#include <algorithm>

using namespace std;

int R, C, StartPoint, cnt = 0;
bool IsVisit[10001][501];
bool check[10001];


void dfs(int tempR, int tempC = 1)
{
    if (tempC == C - 1)
    {
        if (!check[StartPoint])
        {
            check[StartPoint] = true;
            cnt++;
        }

        return;
    }

    if (tempR - 1 >= 0 && !IsVisit[tempR - 1][tempC])
    {
        IsVisit[tempR - 1][tempC] = true;
        dfs(tempR - 1, tempC + 1);

        if (check[StartPoint])
            return;


        //IsVisit[tempR - 1][tempC] = false;
    }

    if (!IsVisit[tempR][tempC])
    {
        IsVisit[tempR][tempC] = true;
        dfs(tempR, tempC + 1);

        if (check[StartPoint])
            return;

        //IsVisit[tempR][tempC] = false;
    }

    if (tempR + 1 < R && !IsVisit[tempR + 1][tempC])
    {
        IsVisit[tempR + 1][tempC] = true;
        dfs(tempR + 1, tempC + 1);

        if (check[StartPoint])
            return;

        //IsVisit[tempR + 1][tempC] = false;
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;

    char tempchar;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            cin >> tempchar;
            if (tempchar == 'x')
                IsVisit[i][j] = 1;
        }

    for (int i = 0; i < R; i++)
    {
        StartPoint = i;
        dfs(i, 1);
    }

    cout << cnt << "\n";

    return 0;
}