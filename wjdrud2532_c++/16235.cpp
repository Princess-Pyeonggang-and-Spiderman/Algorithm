#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M, year;
int arr[11][11];    // 양분 위치
int A[11][11];      // 땅에 더할 양분 값

// (0, 0) 기준으로 (+1, +1) ~ (-1, -1) 까지
int rangeX[] = {1,  1,  1, 0,  0, -1, -1, -1};
int rangeY[] = {1,  0, -1, 1, -1, -1,  0,  1};

vector<int> tempv;
vector<vector<int> > tempv2(11);
vector<vector<vector<int> > > liveTree(11, tempv2);
vector<vector<vector<int> > > deadTree(11, tempv2);


/*
 봄에는 나무가 자신의 나이만큼 양분을 먹고, 나이가 1 증가한다. 각각의 나무는 나무가 있는 1×1 크기의 칸에 있는 양분만 먹을 수 있다. 하나의 칸에 여러 개의 나무가 있다면, 나이가 어린 나무부터 양분을 먹는다. 만약, 땅에 양분이 부족해 자신의 나이만큼 양분을 먹을 수 없는 나무는 양분을 먹지 못하고 즉시 죽는다.
 */
void spring(int currentYear)
{
    // 심어진 나무의 위치는 liveTree에 있음
    // liveTree의 위치에 나무가 존재한다면 양분을 먹을 수 있는지 확인
    //  먹을 수 있다면 먹고 나이 증가
    //  먹을 수 없다면 0으로 만들고 deadTree에 죽기 전 나이 추가
    for(int i = 1; i <= N; i ++)
    {
        for(int j = 1; j <= N; j ++)
        {
            sort(liveTree[i][j].begin(), liveTree[i][j].end());
            
            for(int k = 0; k < liveTree[i][j].size(); k ++) // 나무가 존재하는 경우, 나이가 적은 순으로 양분 먹임
            {
                if(arr[i][j] >= liveTree[i][j][k] && liveTree[i][j][k] != 0)
                {
                    arr[i][j] -= liveTree[i][j][k]; // 양분 값을 나무 나이만큼 빼기
                    liveTree[i][j][k] ++;           // 나무 나이 ++
                }
                else    // 양분이 충분하지 않다면
                {
                    deadTree[i][j].push_back(liveTree[i][j][k]);
                    liveTree[i][j][k] = 0; // 나무 죽음
                    liveTree[i][j].erase(liveTree[i][j].begin() + k);
                    k --;
                }
            }
        }
    }
    
    return ;
}

// 여름에는 봄에 죽은 나무가 양분으로 변하게 된다. 각각의 죽은 나무마다 나이를 2로 나눈 값이 나무가 있던 칸에 양분으로 추가된다. 소수점 아래는 버린다.
void summer(int currentYear)
{
    for(int i = 1; i <= N; i ++)
    {
        for(int j = 1; j <= N; j ++)
        {
            for(int k = 0; k < deadTree[i][j].size(); k ++)     // 죽은 나무가 존재한다면
            {
                arr[i][j] += deadTree[i][j][k] / 2; // 양분 추가
                deadTree[i][j][k] = 0;
            }
            
            for(int k = 0; k < deadTree[i][j].size(); k ++)
            {
                deadTree[i][j].pop_back();
            }
        }
    }
    
    return ;
}

/*
 가을에는 나무가 번식한다. 번식하는 나무는 나이가 5의 배수이어야 하며, 인접한 8개의 칸에 나이가 1인 나무가 생긴다. 어떤 칸 (r, c)와 인접한 칸은 (r-1, c-1), (r-1, c), (r-1, c+1), (r, c-1), (r, c+1), (r+1, c-1), (r+1, c), (r+1, c+1) 이다. 상도의 땅을 벗어나는 칸에는 나무가 생기지 않는다.
 */
void fall(int currentYear)
{
    for(int i = 1; i <= N; i ++)
    {
        for(int j = 1; j <= N; j ++)
        {
            for(int k = 0; k < liveTree[i][j].size(); k ++) // 나무가 존재하고
            {
                // 나이가 5가 넘고                5의 배수인 경우
                if(liveTree[i][j][k] >= 5 && liveTree[i][j][k] % 5 == 0)
                {
                    for(int l = 0; l < 8; l ++)
                    {
                        int tempx = i + rangeX[l];
                        int tempy = j + rangeY[l];
                        if(1 <= tempx && tempx <= N && 1 <= tempy && tempy <= N)    // 범위 안에 존재하는 경우
                        {
                            liveTree[tempx][tempy].push_back(1);    // 나이 1의 나무 추가
                        }
                    }
                }
            }
        }
    }
    return ;
}

// 겨울에는 S2D2가 땅을 돌아다니면서 땅에 양분을 추가한다. 각 칸에 추가되는 양분의 양은 A[r][c]이고, 입력으로 주어진다.
void winter(int currentYear)
{
    for(int i = 1; i <= N; i ++)
    {
        for(int j = 1; j <= N; j ++)
        {
            arr[i][j] += A[i][j];
        }
    }
    return ;
}

int main()
{
    cin >> N >> M >> year;
    
    for(int i = 1; i <= N; i ++)
    {
        for(int j = 1; j <= N; j ++)
        {
            cin >> A[i][j];     // 매년 추가할 양분의 값
            arr[i][j] = 5;      // 초기 땅의 양분값
        }
    }
    
    for(int i = 1; i <= M; i ++)
    {
        int x, y, treeYear;
        cin >> x >> y >> treeYear;  // 초기 땅의 나무 위치 및 나이
        liveTree[x][y].push_back(treeYear);
    }
    
    // 년도만큼 반복
    for(int i = 0; i < year; i ++)
    {
        spring(i);
        summer(i);
        fall(i);
        winter(i);
    }
    
    int survivalTreeNum = 0;
    for(int i = 1; i <= N; i ++)
    {
        for(int j = 1; j <= N; j ++)
        {
            for(int k = 0; k < liveTree[i][j].size(); k ++)
            {
                if(liveTree[i][j][k] >= 1)
                    survivalTreeNum ++;
            }
        }
    }
    
    cout << survivalTreeNum << "\n";
    
}
