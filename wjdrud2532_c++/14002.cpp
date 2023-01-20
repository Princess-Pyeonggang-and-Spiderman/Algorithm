#include <iostream>
#include <algorithm>

using namespace std;

int N, MaxLength = 0;
int arr[1001];
int dp[1001];

void PrintNum(int StartPoint, int PrintPoint)
{
    if(PrintPoint == 0)
        return ;

    int tempnum = 0;
    for(int i = StartPoint; i >= 0; i --)
    {
        if(dp[i] == PrintPoint)
        {
            //cout << "maxlength = " << PrintPoint << "   i = " << i << " arr = " << arr[i] << " \n";
            PrintNum(i - 1, PrintPoint - 1);
            tempnum = arr[i];
            break;
        }
    }

    cout << tempnum << " ";

    return ;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        dp[i] = 1;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            if (arr[i] > arr[j] && dp[j] >= dp[i] - 1)
                dp[i] = dp[j] + 1;
        }
        if (dp[i] > MaxLength)
            MaxLength = dp[i];
    }

    cout << MaxLength << "\n";
    //위 과정은 11053 가장 긴 증가하는 수열 과 같음

    //뒤에서부터 재귀적으로 값을 출력한다
    PrintNum(N - 1, MaxLength);

}