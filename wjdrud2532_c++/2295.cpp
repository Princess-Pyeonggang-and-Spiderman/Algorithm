#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int N;
int maxNum = 0;
int arr[1001];
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

//    fill_n(arr, N, -1);

    for(int i = 0; i < N; i ++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    // 3 5 10 = 18
    // 3 5 = 18 - 10
    for(int i = 0; i < N; i ++)
    {
        for(int j = i; j < N; j ++)
        {
            v.push_back(arr[i] + arr[j]);
            // 3 + 5, 3 + 10, 3 + 18 ...
        }
    }

    sort(v.begin(), v.end());

    for(int i = N - 1; i >= 0; i --)
    {
        for(int j = i - 1; j >= 0; j --)
        {
            // 18 - 10 이 v 안에 존재하는 경우 = (3 + 5) -> 세 수의 합이 존재,  최대값 비교
            if(binary_search(v.begin(), v.end(), arr[i] - arr[j]))
            {
//                maxNum = max(maxNum, arr[i]);
//                cout << arr[j] << "\n";
                cout << arr[i] << "\n";
                return 0;
            }
        }
    }

    cout << maxNum << "\n";
//    cout << "dddd \n";

    return 0;
}
