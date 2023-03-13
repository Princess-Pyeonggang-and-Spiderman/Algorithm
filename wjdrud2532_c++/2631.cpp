#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int T, K;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while(T --)
    {
        cin >> K;

        priority_queue<long long int, vector<long long int>, greater<long long int> > pq;
        long long int result = 0;

        int tempnum;
        for(int i = 0; i < K; i ++)
        {
            cin >> tempnum;
            pq.push(tempnum);
        }

        long long int num1, num2;
        while(pq.size() > 1)
        {
            num1 = pq.top();
            pq.pop();

            num2 = pq.top();
            pq.pop();

            result += (num1 + num2);
            pq.push(num1 + num2);
        }

        cout << result << "\n";
    }
    return 0;
}
