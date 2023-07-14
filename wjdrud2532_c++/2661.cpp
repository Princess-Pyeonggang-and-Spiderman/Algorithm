//2661 좋은 수열

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
string str = "";
bool isEnd = false;

bool checkarr(string tempstr)
{
    // 가장 끝에서부터 비교 가능한 곳 까지 비교
    string str1;
    string str2;

    // tempstr = 123456789
    for(int i = tempstr.size() - 1, cnt = 1; i >= 0; i --, cnt ++)
    {
        if(i * 2 < tempstr.size())
            break;

        str1 = tempstr.substr(i, cnt);
        str2 = tempstr.substr(i - cnt, cnt);

        if(str1 == str2)
        {
            return false;
        }
    }

//    cout << str1 << "\n" << str2 << "\n\n";
    return true;
}

void dfs(string tempstr)
{
    if(checkarr(tempstr) && tempstr.size() == N)
    {
        cout << tempstr << "\n";
        isEnd = true;
        return ;
    }

    // 좋은 수열이 아니라면 가장 뒤의 것을 pop
    if(checkarr(tempstr) == false)
    {
        tempstr.pop_back();
        return;
    }

    for(int i = 1; i <= 3; i ++)
    {
        // 수열 길이를 늘려야 할 경우
        if(tempstr.size() < N && !isEnd)
        {
            dfs(tempstr + to_string(i));
        }

    }
}

int main()
{
    cin >> N;

    dfs("1");

//    cout << "last   : ";
//    cout << str << "\n";

    /*
     수열을 생성
     좋은 수열인지 확인
     좋은 수열이면 str추가
     좋은 수열이 아니라면 이전 dfs로 돌아가 다른 수 다 넣어보고 좋은 수열인지 확인
        여기서도 좋은 수열이 아니라면 이전 값을 뺀다
     */

    return 0;
}

//1213123132123121312313212
//1213123132123121312313212

//121312313212312131231321312132123121312313212312131
//121312313212312131231321312132123121312313212312131
