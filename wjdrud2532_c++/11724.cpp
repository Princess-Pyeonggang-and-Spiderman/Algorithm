#include <iostream>
#include <vector>

using namespace std;

int N, M, cnt = 0;
vector<int> V[1001];
bool IsVisit[1001] = {0, };

void dfs(int StartPoint)
{
    //방문하지 않은 상태로 들어왔으므로 방문 상태로 설정
    IsVisit[StartPoint] = true;
    
    int temp;
    
    //현재 방문한 노드에 연결된 지점만큼 반복한다
    for(int i = 0; i < V[i].size(); i ++)
    {
        temp = V[StartPoint][i];
        
        //연결된 지점을 방문하지 않았다면 재귀로 방문한다
        if(IsVisit[temp] == false)
        {
            dfs(i);
        }
    }
    return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    int temp1, temp2;
    for(int i = 0; i < M; i ++)
    {
        cin >> temp1 >> temp2;
        //양방향 노드 연결
        V[temp1].push_back(temp2);
        V[temp2].push_back(temp1);
    }
    
    for(int i = 1; i <= N; i ++)
    {
        if(IsVisit[i] == false) //방문하지 않은 경우
        {
            cnt ++;
            dfs(i);
        }
    }
    
    cout << cnt << "\n";
    
    return 0;
}
