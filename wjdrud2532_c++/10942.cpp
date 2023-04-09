#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int arr[2001] = {0, };          // 최대 입력 개수
bool pel[2001][2001] = {0, };   // 최대 배열

// start, end가 pel 일 경우 start + 1, end - 1 모두 pel로 만들어주는 함수
void alsoPel(int start, int end)
{
    while(start <= end)
    {
        pel[start][end] = true;

        start ++;
        end --;
    }

    return ;
}

// start, end로 시작하는 배열이 pel 인지 확인하는 함수
bool isPel(int start, int end)
{
    while(start <= end)
    {
        if(arr[start] != arr[end])
            return false;

        start ++;
        end --;
    }

    if(start <= end)
        return true;
    else
        return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 1; i <= N; i ++)
        cin >> arr[i];

    // 중앙, start ++, end -- 를 확인
    for(int i = 1; i <= N - 1; i ++)
    {
        for(int j = N; j > 1; j --)
        {
            if(pel[i][j] == false)  // pel 인지 확인 안했을 경우
            {
                if(isPel(i, j)) // pel 인지 확인하고
                {
                    alsoPel(i, j); // pel 일 경우 이하 나머지 모두 pel 로 설정
                }
            }
        }
    }

    // 1, 1~N 까지의 pel을 확인
    for(int i = 1; i <= N; i ++)
    {
        if(pel[1][i] == false)
        {
            if(isPel(1, i))
            {
                alsoPel(1, i);
            }
        }
    }

    // 1~N, N 까지의 pel을 확인
    for(int i = N; i >= 1; i --)
    {
        if(pel[i][N] == false)
        {
            if(isPel(i, N))
            {
                alsoPel(i, N);
            }
        }
    }

    cin >> M;

    for(int i = 0; i < M; i ++)
    {
        int start, end;
        cin >> start >> end;

        // pel = true 일 경우 1 출력
        if(pel[start][end])
            cout << "1\n";
        else
            cout << "0\n";
    }

    return 0;
}

