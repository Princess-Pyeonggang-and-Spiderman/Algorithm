/*
 방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.
 
 첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. (1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2) 둘째 줄부터 M개의 줄에 간선의 양 끝점 u와 v가 주어진다. (1 ≤ u, v ≤ N, u ≠ v) 같은 간선은 한 번만 주어진다.
 첫째 줄에 연결 요소의 개수를 출력한다.
 
 
 
 예제 1
 6 5
 1 2
 2 5
 5 1
 3 4
 4 6
 출력 2
 
 예제 2
 6 8
 1 2
 2 5
 5 1
 3 4
 4 6
 5 4
 2 4
 2 3
 출력 1
 
 1부터 시작해서 다시 1로 돌아오는 경우 연결횟수 1로 생각
 1. 전부 입력 다 받고 반복분 돌려가면서 하는 방법
 2. 입력 받을 때 연결된 것이 없다면 queue를 하나 만들어 끝에 첫 값과 끝 값을 비교
 
 한 간선에 2개의 연결이 있는 경우도 고려해야함
 재귀?
 */

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

/*
 
 
 
 */
