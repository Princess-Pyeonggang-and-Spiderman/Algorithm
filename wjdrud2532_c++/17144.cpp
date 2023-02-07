#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int R, C, T;
int PurifierUp = 0, PurifierDown = 0;
int arr[51][51];

void Print()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";
}

int DivideAndPlus()
{
    //나누기 계산 결과 담을 임시 배열 생성, 0으로 초기화
    int temparr[51][51] = {0,};

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            int tempcnt = 0, tempnum = arr[i][j] / 5;

            //왼쪽 확산 가능한 경우
            if (j - 1 >= 0 && arr[i][j - 1] != -1)
            {
                temparr[i][j - 1] += tempnum;
                tempcnt++;
            }

            //오른쪽
            if (j + 1 < C)
            {
                temparr[i][j + 1] += tempnum;
                tempcnt++;
            }

            //위
            if (i - 1 >= 0)
            {
                temparr[i - 1][j] += tempnum;
                tempcnt++;
            }

            //아래
            if (i + 1 < R)
            {
                temparr[i + 1][j] += tempnum;
                tempcnt++;
            }

            //가운데
            temparr[i][j] += arr[i][j] - (tempnum * tempcnt);
        }
    }

    //나누기 결과를 원본으로 복사
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            arr[i][j] = temparr[i][j];
        }
    }

    //임시배열 초기화 과정에서 사라진 공기청정기 위치 재설정
    arr[PurifierUp][0] = -1;
    arr[PurifierDown][0] = -1;

    return 0;
}

void Wind()
{
    // 공기청정기에 공기가 빨려들어가는 나오는 곳 순서로 진행

    //위쪽
    //arr[PurifierUp - 1][0] = 0; //  4ms 줄어듦
    for (int i = PurifierUp - 1; i - 1 >= 0; i--)
        arr[i][0] = arr[i - 1][0];

    for (int j = 0; j + 1 < C; j++)
        arr[0][j] = arr[0][j + 1];

    for (int i = 0; i + 1 <= PurifierUp; i++)
        arr[i][C - 1] = arr[i + 1][C - 1];

    for (int j = C - 1; j - 1 >= 1; j--)
        arr[PurifierUp][j] = arr[PurifierUp][j - 1];

    // 공기 나오는 부분
    arr[PurifierUp][1] = 0;

    //아래쪽
    //arr[PurifierDown + 1][0] = 0; //
    for (int i = PurifierDown + 1; i + 1 <= R - 1; i++)
        arr[i][0] = arr[i + 1][0];

    for (int j = 0; j + 1 < C; j++)
        arr[R - 1][j] = arr[R - 1][j + 1];

    for (int i = R - 1; i - 1 >= PurifierDown; i--)
        arr[i][C - 1] = arr[i - 1][C - 1];

    for (int j = C - 1; j - 1 >= 1; j--)
        arr[PurifierDown][j] = arr[PurifierDown][j - 1];

    arr[PurifierDown][1] = 0;

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C >> T;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> arr[i][j];

            //청정기 위치 저장
            if (arr[i][j] == -1)
            {
                if (!PurifierUp)
                    PurifierUp = i;
                else
                    PurifierDown = i;
            }
        }
    }

    for (int i = 0; i < T; i++)
    {
        DivideAndPlus();
        Wind();
        //Print();
    }

    int result = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            result += arr[i][j];
        }
    }

    //청정기 값 삭제
    result += 2;

    cout << result << "\n";

    return 0;
}