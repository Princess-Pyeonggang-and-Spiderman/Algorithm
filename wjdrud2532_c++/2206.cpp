#include <iostream>

#include <queue>
#include <climits>

using namespace std;

int N, M;

//[x][y][0] 벽을 부순 상태에서 (x, y) 까지 도착하는데 이동한 거리
//[x][y][1] 벽을 부수지 않은 상태의 거리
int isVisit[1001][1001][2];
bool arr[1001][1001];

bool PassWall;

int minLength = INT_MAX;

queue<pair<int, int>> WallCoordinate;

int bfs()
{
    queue<pair<pair<int, int>, int>> tempQ;
    
    // (1, 1) , 방문함
    tempQ.push({{1,1}, 1});
    isVisit[1][1][1] = 1;
    
    int CurrentN, CurrentM, Currentlength;
    
    pair<pair<int, int>, int> tempPair;
    
    int NextN, NextM;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    while(!tempQ.empty())
    {
        //cout << "1";
        
        tempPair = tempQ.front();
        tempQ.pop();
        
        // (N, M), length
        CurrentN = tempPair.first.first;
        CurrentM = tempPair.first.second;
        Currentlength = tempPair.second;
        
        cout << "(" << CurrentN << ", " << CurrentM << ")\n";
        
        
        // 목적지에 도달한 경우
        if(CurrentN == N && CurrentM == M)
        {
            return isVisit[CurrentN][CurrentM][Currentlength];
        }
        
        for(int i = 0; i < 4; i ++)
        {
            NextN = CurrentN + dx[i];
            NextM = CurrentM + dy[i];
            
            if( (NextM > 0 && NextM <= M) && (NextN > 0 && NextN <= N))
            {
                if(arr[NextN][NextM] == 1 && Currentlength == 1)
                {
                    isVisit[NextN][NextM][0] = isVisit[CurrentN][CurrentM][Currentlength] + 1;
                    tempQ.push({{NextN, NextM}, 0});
                }
                else if(arr[NextN][NextM] == 0 && isVisit[NextN][NextM][Currentlength] == 0)
                {
                    isVisit[NextN][NextM][Currentlength] = isVisit[CurrentN][CurrentM][Currentlength] + 1;
                    tempQ.push({{NextN, NextM}, Currentlength});
                }
            }
        }
    }
    return -1;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> N >> M;
    
    int tempnum = 0;
    char tempstring[1001];
    
    for (int i = 1; i <= N; i++)
    {
        cin >> tempstring;
        
        for(int j = 1; j <= M; j ++)
        {
            if (tempstring[j - 1] - '0' == 1)
                WallCoordinate.push(make_pair(i, j));
            
            arr[i][j] = tempstring[j - 1] - '0';
        }
    }
    
    minLength = bfs();
    
    cout << minLength << "\n";
    
    return 0;
}
