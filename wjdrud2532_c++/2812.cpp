#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int strLength, K;
    string str, result;

    cin >> strLength >> K;
    cin >> str;

    for(int i = 0; i < strLength; i ++)
    {

        while(K && result.length() > 0 && str[i] > result.back())
        {
            K --;
            result.pop_back();
        }

        if(i + K == strLength)
            break;

        result.push_back(str[i]);

    }

    cout << result << "\n";

    return 0;
}
