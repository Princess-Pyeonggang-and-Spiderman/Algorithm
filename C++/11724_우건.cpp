#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief 
 * 간단한 dfs로 연결된 곳을 모두 방문하면서 visited를 1로 수정
 * @param x : 방문하는 노드 번호
 */
void dfs(int x);

// 간선 정보와 방문 여부를 저장할 변수
vector< vector<int> > graph(1001);

int visited[1001];

int main()
{
    // 입력
    int n, m, a, b;
    cin >> n >> m;

    for (int i = 0; i < m; i++) 
    {
        cin >> a >> b;
        graph.at(a).push_back(b);
        graph.at(b).push_back(a);
    }

    // 1 ~ n 까지 반복하여 방문하지 않은 곳이라면 dfs를 진행
    int result = 0;
    for (int i = 1; i < n + 1; i++)
    {
        if (!visited[i])
        {
            result += 1;
            dfs(i);
        }
    }

    cout << result << "\n";

    return 0;
}

void dfs(int x)
{
    visited[x] = 1;
    for (int i = 0; i < graph[x].size(); i++)
    {
        if (!visited[graph[x][i]])
        {
            dfs(graph[x][i]);
        }
    }
}