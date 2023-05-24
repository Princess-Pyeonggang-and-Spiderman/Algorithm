#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    //48ms -> 12ms
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str, boom, stackstr;

    cin >> str >> boom;

    for(int i = 0; i < str.length(); i ++)
    {
        //
        stackstr.push_back(str[i]);

        //뒤부터 비교
        if(stackstr.back() == boom.back())
        {
            //boom이 있을 가능성 체크
            if(stackstr.length() >= boom.length())
            {
                bool isBoom = true;

                //끝부분을 기준으로 문자열을 비교
                for(int j = 0; j < boom.length(); j ++)
                {
                    if(stackstr[stackstr.length() - boom.length() + j] != boom[j])
                    {
                        isBoom = false;
                        break;
                    }
                }

                //폭탄이라면 그 크기만큼 pop
                if(isBoom)
                {
                    for(int j = 0; j < boom.length(); j ++)
                    {
                        stackstr.pop_back();
                    }
                }
            }
        }
    }

    if(!stackstr.empty())
        cout << stackstr << "\n";
    else
        cout << "FRULA\n";
}