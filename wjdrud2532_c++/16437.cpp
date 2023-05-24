#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
long long int result = 0;

vector<int> v[123457];
int howMany[123457];

// 이거 필요없이 W가 나오는 경우 -로 저장하는 방법
bool isWolf[123457];

//bool isVisit[123457];


long long int dfs(int start)
{

    // 끝에 도달한 경우
    if(v[start].empty())
    {
        if(!isWolf[start])  // 양일경우 그 값 반환
            return howMany[start];
        else
            return 0;
    }

    long long int tempsum = 0;
    //tempsum += howMany[start];

    for(int i = 0; i < v[start].size(); i ++)
    {
        int next = v[start][i];
        tempsum += dfs(next);
    }

    int tempnum = howMany[start];;

    // 양일 경우
    if(!isWolf[start])
        tempsum += tempnum;
    else    // 늑대일 경우 -
        tempsum -= tempnum;

    if(tempsum < 0)
        return 0;
    else
        return tempsum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    // 2 부터!
    for(int i = 2; i <= N; i ++)
    {
        int nextIsland;
        char tempchar;
        //                  개체수
        cin >> tempchar >> howMany[i] >> nextIsland;

        if(tempchar == 'W')
            isWolf[i] = true;

        // i 번째 섬은 nextIsland과 연결되어 있다.
        v[nextIsland].push_back(i);
    }

    result = dfs(1);

    cout << result << "\n";

    return 0;
}
