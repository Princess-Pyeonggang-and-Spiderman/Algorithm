#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int temparr[7];
bool arr[5][5] = {0, };

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int result = 0;

vector<int> v;
vector<bool> vVisited(25, true);

bool bfs()
{
    bool isVisit[5][5] = {0, }; // 연결확인을 위한 임시 배열

    for(int i = 0; i < 7; i ++) // 선택한 좌표 1로 설정
        isVisit[temparr[i]/5][temparr[i]%5] = 1;

    queue<int> q;
    q.push(temparr[0]); // 첫 값 push
    int cnt = 0;

    while(!q.empty())
    {
        int current = q.front();
        q.pop();

        for(int dir = 0; dir < 4; dir ++)   // 상하좌우 연결되었는지 확인
        {
            int ny = current / 5 + dy[dir];
            int nx = current % 5 + dx[dir];

            if(0 <= nx && 0 <= ny && nx < 5 && ny < 5)
            {
                if(isVisit[ny][nx] == 1)    // 범위 안쪽이고 방문하지 않았고 선택되었다면 방문
                {
                    isVisit[ny][nx] = 0;
                    cnt ++;
                    q.push(ny*5 + nx);
                }
            }
        }
    }
    if(cnt == 7)    // 7개 모두 연결되어 있다면 true 반환
        return true;

    return false;
}

void combi()    // next_permutation 으로 조합 구현
{
    for(int i = 0; i < 25; i ++)        // 총 25개 중에서
        v.push_back(i);

    for(int i = 0; i < v.size() - 7; i ++) // 선택하고자 하는 개수 7개
        vVisited[i] = false;

    do {
        fill_n(temparr,7, 0);   // 선택된 좌표 저장을 위한 초기화
        int temparrcnt = 0;
        int somCount = 0;

        for(int i = 0; i < v.size(); i ++)
        {
            if(vVisited[i])
            {
                temparr[temparrcnt++] = v[i];   // 순서 저장

                if(arr[v[i] / 5][v[i] % 5] == 1)    // 1이라면 cnt ++
                    somCount ++;
            }
        }

        if(somCount >= 4) // 4이상이면 연결되었는지 확인
        {
            if(bfs())
                result ++;
        }
    }while(next_permutation(vVisited.begin(), vVisited.end()));

    return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < 5; i ++)
    {
        for(int j = 0; j < 5; j ++)
        {
            char tempchar;
            cin >> tempchar;

            if(tempchar == 'Y')
                arr[i][j] = 0;
            else
                arr[i][j] = 1;
        }
    }

    combi();

    cout << result << "\n";

    return 0;
}