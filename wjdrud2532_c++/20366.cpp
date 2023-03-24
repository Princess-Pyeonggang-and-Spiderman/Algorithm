#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int N;
long long int arr[601] = {0, };

int elza1, elza2;
int anna1, anna2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i ++)
        cin >> arr[i];

    long long int answer = LONG_MAX;

    sort(arr, arr + N);

    for(int i = 0; i < N - 3; i ++)
    {
        for(int j = i + 3; j < N; j ++)
        {
            int start = i + 1, end = j - 1;

            while(start < end)
            {
                long long int anna = arr[i] + arr[j];
                long long int elsa = arr[start] + arr[end];

                long long int tempanswer = anna - elsa;

                if(abs(tempanswer) < answer)
                    answer = abs(tempanswer);

                if(tempanswer < 0)  // elsa 가 더 크다면 elsa의 크기를 줄인다
                    end --;
                else
                    start ++;
            }
        }
    }

    cout << answer << "\n";

    return 0;
}
