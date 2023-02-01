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
        //push 하려는 값보다 작은 값이 앞에 있고 지울 수 있는 개수가 남아있다면 pop 한다
        while(K && result.length() > 0 && str[i] > result.back())
        {
            K --;
            result.pop_back();
        }

        //끝까지 갔을 경우 뒤의 값을 자른다
        if(i + K == strLength)
            break;

        result.push_back(str[i]);

    }

    cout << result << "\n";

    return 0;
}
