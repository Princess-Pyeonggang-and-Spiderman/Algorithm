/*
 그냥 dfs로 하면
6
NYYNYN
YNYNNN
YYNYNN
NNYNNN
YNNNNY
NNNNYN
 
에서 첫 번째 Y로 2 방문
2 탐색 마치고 돌아와 두 번째 Y로 3을 갈 때 2방문처리 되어서 3가지 못하기 때문에 틀림
해결하기 위해 vector로 입력 받을 때 Y를 탐지하여 그 수 만큼 반복하도록 한다
*/

#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int N;
char twoFriend[51][51];
bool isVisit[51] = {0, };
vector<int> v[51];
int maxCnt = 0;
int tempCnt = 0;

void searchFriend(int i, int cnt)
{
    isVisit[i] = true;
    
    if(cnt == 2)
        return;
    
    for(int j = 0; j < v[i].size(); j ++)
    {
        searchFriend(v[i][j], cnt + 1);
    }
    
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> N;
    
    char tempchar;
    
    for(int i = 0; i < N; i ++)
    {
        for(int j = 0; j < N; j ++)
        {
            cin >> tempchar;
            if(tempchar == 'Y')
                v[i].push_back(j);
        }
    }
    
    for(int i = 0; i < N; i ++)
    {
        tempCnt = 0;
        
        searchFriend(i, 0);
        
        for(int k = 0; k < N; k ++)
        {
            if(isVisit[k] == true)
                tempCnt ++;
        }
        
        if(maxCnt < tempCnt)
            maxCnt = tempCnt;
        
        fill_n(isVisit, N, false);
        //memset(isVisit, false, sizeof(isVisit));
    }
    
    cout << maxCnt - 1 << "\n";
}

