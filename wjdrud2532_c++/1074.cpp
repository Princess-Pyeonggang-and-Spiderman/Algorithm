#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int N, r, c, StartValue = 0;


void FindNum(int NextR, int NextC, int CurrentN)
{
    cout << NextR << " " << NextC << " " << CurrentN << " " << StartValue << "\n";

    //2의 N제곱, 현재 탐색할 배열의 크기
    int NSqrt = pow(2, CurrentN);

    if(CurrentN == 0)
        return;

    //4가지 분면을 탐색

    //1사분면
    if (NextR < NSqrt / 2 && NextC < NSqrt / 2)
    {
        FindNum(NextR - (NSqrt / 2) + 1, NextC - (NSqrt / 2) + 1, CurrentN - 1);
    }

        //우상단
    else if (NextR < NSqrt / 2 -1 && NextC < NSqrt)
    {
        StartValue += ((NSqrt*NSqrt) / 4) * 1;
        FindNum(NextR, NextC - (NSqrt / 2) + 1, CurrentN - 1);
    }

        //좌하단
    else if (NextR < NSqrt && NextC < NSqrt / 2)
    {
        StartValue += ((NSqrt*NSqrt) / 4) * 2;
        FindNum(NextR - (NSqrt / 2) + 1, NextC, CurrentN - 1);
    }

        //우하단
    else
    {
        StartValue += ((NSqrt*NSqrt) / 4) * 3;
        FindNum(NextR , NextC, CurrentN - 1);
    }

    return;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> r >> c;

    FindNum(r, c, N);

    cout << StartValue << "\n";

    /*
     * N 제곱으로
     * 배열은 0부터 시작
     *
     * 행,열은 0부터 시작
     * r이 행(세로)
     *
     * 0 2 8 10 32 34 40 42 128
     * 0 1 3    5           7
     *
     *
     * n = 3일 때 최대는 64 라고 하면
     * 각 부분을 1/4, 시작 값은 64 / 4 * 0, 1, 2, 3
     *
     *
     *
     *
     * 입력으로 주어진 r, c의 값이 어느 분면에 있는지는 입력받은 n의 값을 통해 알 수 있다
     * 이를 통해 속해있는 분면으로 간다
     * 그 분면의 시작 값을 알아둔다, 그리고 줄어든 분면 크기만큼 r과 c의 값을 조정한다(빼기 n^2의 / 2)
     *
     * 마지막엔 00 01 10 11만 남는다 -> 시작값을 통해 값을 알아낸다
     *
     */


    return 0;
}