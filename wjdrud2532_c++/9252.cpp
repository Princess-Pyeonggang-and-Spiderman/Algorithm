#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string s1, s2;

int dp[1001][1001] = {0,};

void printLCS(int i, int j)
{
    if (dp[i][j] == 0)
        return;

    if (s1[i - 1] == s2[j - 1])
    {
        printLCS(i - 1, j - 1);
        cout << s1[i - 1];
    }
    else
    {
        if (dp[i - 1][j] > dp[i][j - 1])
            printLCS(i - 1, j);
        else
            printLCS(i, j - 1);
    }

    return;
}

void findLCS(string s1, string s2)
{
    for (int i = 1; i <= s1.length(); i++)
    {
        for (int j = 1; j <= s2.length(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                if (dp[i][j] == 0)
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
            }

                //LCS 1과 다르게 else 하지 않으면 문장 출력에 오류 발생
                //길이는 똑같이 출력할 수 있지만 문장을 역추적 할 때 잘못된 방향으로 돌아갈 수 있음
            else
            {
                //아래 두 코드 같음
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                //dp[i][j] = max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
    }

    return;
}

int main()
{
    cin >> s1 >> s2;

    //최장거리 구함
    findLCS(s1, s2);

    cout << dp[s1.length()][s2.length()] << "\n";

    if (dp[s1.length()][s2.length()] != 0)
    {
        //최장 거리 길이를 역추적하여 재귀로 LCS 문자열을 출력
        printLCS(s1.length(), s2.length());
    }

    return 0;
}



//아래 전부 시간초과
/*
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string s1, s2;

int dp[1001][1001] = {0,};
vector<pair<int, string>> v[1001][1001];

pair<int, string> p[1001][1001];

void findLCS(string s1, string s2)
{
    for(int i = 1; i <= s1.length(); i ++)
    {
        p[0][i].second = s1[i];
    }

    for(int i = 1; i <= s2.length(); i ++)
    {
        p[i][0].second = s2[i];
    }



    for (int i = 1; i <= s1.length(); i++)
    {
        for (int j = 1; j <= s2.length(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
                if (p[i][j].first == 0)
                {
                    p[i - 1][j - 1].first++;
                    p[i][j].second += p[i - 1][j - 1].second;
                }

            // 문자열 붙히기
            pair<int, string> tempP;

            //뭘로 max 비교를 하는거지?
            tempP = max({p[i - 1][j - 1], p[i - 1][j], p[i][j - 1]});

            p[i][j].first += tempP.first;
            p[i][j].second += tempP.second;
        }
    }

    return;
}

int main()
{
    cin >> s1 >> s2;

    findLCS(s1, s2);

    for (int i = 0; i <= s1.length(); i++)
    {
        for (int j = 0; j <= s2.length(); j++)
        {
            cout.width(5);
            cout << p[i][j].second << " ";
        }
        cout << "\n";
    }

    cout << p[s1.length()][s2.length()].first << "\n";

    if (p[s1.length()][s2.length()].first == 0)
        return 0;

    cout << p[s1.length()][s2.length()].second << "\n";

    return 0;
}
*/