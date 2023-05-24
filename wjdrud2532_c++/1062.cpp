

//시간초과 6%
/*
#include <iostream>
#include <cstring>
#include <bitset>

//#include <algorithm>
//next_permutation(Arr.begin(), Arr.end());
using namespace std;

int N, K;
bool alpa[26] = {0,};

int alpanum[50] = {0,};

bool temptempalpa[26] = {0,};

int tempnum = 0;
int maxcnt = 0;
int tempcnt = 0;

void boolToInt()
{
    //26개의 알파벳 중에서 K - 5 개를 선택한 값을 bit로 표현

//    tempnum = 0;
//
//    tempnum |= 1 << ('a' - 'a');
//    tempnum |= 1 << ('n' - 'a');
//    tempnum |= 1 << ('t' - 'a');
//    tempnum |= 1 << ('c' - 'a');
//    tempnum |= 1 << ('i' - 'a');

    tempnum = 532741;

    for (int i = 0; i < 26; i++)
    {
        if (temptempalpa[i])
        {
            tempnum |= 1 << i;
        }
    }
}

void dfs(int count, int startPoint)
{
    if (count == K - 5)
    {
        //모든 값을 판별

        //현재 선택된 값들의 bit
        boolToInt();

        tempcnt = 0;

        for (int i = 0; i < N; i++)
        {
            if ((tempnum & alpanum[i]) == alpanum[i])
            {
//                cout << "aaaaaaaaaaaaaaaaaaaa\n";
//                cout << bitset<26>(tempnum) << "\n";
//                cout << bitset<26>(alpanum[i]) << "\n\n";
                tempcnt++;
            }
        }

        if (tempcnt > maxcnt)
            maxcnt = tempcnt;
    }

    for (int i = startPoint; i < 26; i++)
    {
        if (alpa[i] && !temptempalpa[i])
        {
            temptempalpa[i] = true;
            dfs(count + 1, i + 1);
            temptempalpa[i] = false;
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //cout << "start\n";

    cin >> N >> K;

    if (K < 5)
    {
        cout << "0\n";
        return 0;
    }

    if (K == 26)
    {
        cout << N << "\n";
        return 0;
    }

//    bit |= 1 << ('a' - 'a');
//    bit |= 1 << ('n' - 'a');
//    bit |= 1 << ('t' - 'a');
//    bit |= 1 << ('c' - 'a');
//    bit |= 1 << ('t' - 'a');

    alpa['a' - 'a'] = true;
    alpa['n' - 'a'] = true;
    alpa['t' - 'a'] = true;
    alpa['c' - 'a'] = true;
    alpa['i' - 'a'] = true;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;

        for (int j = 4; j < s.length(); j++)
        {
//            if (j < 4)
//                continue;

            if (j > s.length() - 5)
                break;

            //  사용된 알파벳 기록
            //arr |= 1 << (s[j] - 'a');

            //전체 입력된 값들
            alpa[s[j] - 'a'] = true;

            //각각 들어있는 값들
            alpanum[i] |= 1 << (s[j] - 'a');
        }
//        cout << bitset<26>(arr) << " ";
//        cout << "\n";
    }

    //새로 들어온 값들의 조합을 구한다
    dfs(0, 0);

    cout << maxcnt << "\n";


    //  26개 중 K개의 1을 갖는 비트를 전부 돌린다 -> 너무 느림

    //  두 bit를 조합해서 1이 k개가 되는 경우 이것으로 and 연산을 통해 통과하는 값을 구한다?

    return 0;
}
*/

//next_permutation 을 사용한 순열조합
//시간초과 2%
/*
 #include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <bitset>

using namespace std;

int N, K, maxcnt = 0;
int alpa[50];
vector<char> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    if(K < 5)
    {
        cout << "0\n";
        return 0;
    }

    if(K == 26)
    {
        cout << N << "\n";
        return 0;
    }

    fill_n(alpa, N, 532741);

    v.push_back('a');
    v.push_back('n');
    v.push_back('t');
    v.push_back('i');
    v.push_back('c');

    string s;
    for(int i = 0; i < N; i ++)
    {
        cin >> s;

        for(int j = 4; j < s.length() - 4; j ++)
        {
            //alpa[s[j] - 'a'] = true;

            alpa[i] |= 1 << (s[j] - 'a');

            //순열 조합을 위한
            auto it = find(v.begin(), v.end(), s[j]);
            if(it == v.end())
                v.push_back(s[j]);
        }
    }

    vector<int> tempV;

    for(int i = 0; i < K;  i ++)
        tempV.push_back(1);

    for(int i = 0; i < v.size() - K; i ++)
        tempV.push_back(0);

    sort(tempV.begin(), tempV.end());

    do
    {
        int BIT = 0;
        int tempcnt = 0;
        for(int i = 0; i < tempV.size(); i ++)
        {
            if(tempV[i] == 1)
            {
                //조합으로 나온 이 값들을 조합하여 비교하면 된다
                BIT |= 1 << (v[i] - 'a');
            }
        }
        //cout << bitset<26>(BIT) << "\n";

        for(int i = 0; i < N; i ++)
        {
            //cout << bitset<26>(alpa[i]) << "\n";
            if((BIT & alpa[i]) == alpa[i])
            {
                tempcnt ++;
            }
        }
        //cout << tempcnt << "  tempcnt    \n";
        if(tempcnt > maxcnt)
            maxcnt = tempcnt;

    } while (next_permutation(tempV.begin(), tempV.end()));

    cout << maxcnt << "\n";

    return 0;
}
 */


#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int N, K, maxcnt = 0;
string s[50];
bool isVisit[26];

void dfs(int count, int startPoint)
{
    //배우고자 하는 단어의 개수가 되었을 경우
    if(count == K - 5)
    {
        int tempcnt = 0;

        //단어들을 읽을 수 있는지 단어의 개수만큼 반복한다
        for(int i = 0; i < N; i ++)
        {
            bool flag = true;

            //단어 하나하나를 비교하며 읽을 수 있는지(isVisit에서 현재 단어가 true 인지) 확인한다
            for(int j = 0; j < s[i].length(); j ++)
            {
                if(!isVisit[s[i][j] - 'a'])
                {
                    //단어를 읽을 수 없다면 중단
                    flag = false;
                    break;
                }
            }
            //단어를 읽을 수 있다면 tempcnt ++ 한다
            if(flag)
                tempcnt ++;
        }

        //최대값을 기록
        if(maxcnt < tempcnt)
            maxcnt = tempcnt;

        return;
    }

    //순열 조합으로 count가 K - 5가 될 때 까지 반복
    for(int i = startPoint; i < 26; i ++)
    {
        if(!isVisit[i])
        {
            isVisit[i] = true;
            dfs(count + 1, i);
            isVisit[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    //K가 5이하, 26인 경우 항상 같은 결과 출력
    if(K < 5)
    {
        cout << "0\n";
        return 0;
    }

    if(K == 26)
    {
        cout << N << "\n";
        return 0;
    }

    //반드시 들어가야하는 5가지 단어 입력
    isVisit['a' - 'a'] = true;
    isVisit['c' - 'a'] = true;
    isVisit['i' - 'a'] = true;
    isVisit['n' - 'a'] = true;
    isVisit['t' - 'a'] = true;

    string tempS;
    for(int i = 0; i < N; i ++)
    {
        cin >> tempS;

        for(int j = 4; j < tempS.length() - 4; j ++)
        {
            //입력받은 단어에서 알고자 하는 부분만 배열에 삽입
            s[i].push_back(tempS[j]);
        }
    }

    dfs(0, 0);

    cout << maxcnt << "\n";

    return 0;
}