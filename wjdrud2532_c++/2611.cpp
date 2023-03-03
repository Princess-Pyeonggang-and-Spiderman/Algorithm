#include <iostream>
#include <type_traits>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<pair<int, int> > v[1001];     // v[i]: i 노드에서 갈 수 있는 노드(first) 와 점수(second)
int indegree[1001] = {0, };         // indegree[i] == 0인 경우 해당 노드로 갈 수 있는 모든 방향을 탐색한 것
int dp[1001];                       // dp[i]: i 에는 해당 노드가 가질 수 있는 가장 큰 점수 값을 가짐
int resultList[1001] = {0, };       // 경로 저장을 위한 List

// 1부터 선택된 경로를 따라 올라가며 끝에서부터 재귀적으로 출력
// 마지막 1은 무한 재귀를 방지하기 위해 출력하지 않는다
void printLink(int next)
{
    if(resultList[next] != 1)
        printLink(resultList[next]);
    cout << resultList[next] << " ";

    return ;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    int start, end, value;
    for (int i = 0; i < M; i ++)
    {
        cin >> start >> end >> value;
        indegree[end] ++;               // 이곳에 도달할 수 있는 방법의 수 ++

        // 출발지            도착지  점수
        v[start].push_back(make_pair(end, value));
    }

    queue<int> q;
    q.push(1);  // 출발지점 1 push

    while (! q.empty())
    {
        int current = q.front();
        q.pop();

        for (int i = 0; i < v[current].size(); i ++)
        {
            int next = v[current][i].first;
            indegree[next] --;

            // current에서 도달할 수 있는 next 노드가 가질 수 있는 가장 큰 값을 비교
            if (dp[current] + v[current][i].second > dp[next])
            {
                dp[next] = dp[current] + v[current][i].second;
                resultList[current] = next;     // current에서 어느 노드의 경로를 방문했는지 기록
            }

            // next가 가질 수 있는 모든 경로를 탐색한 경우 push
            if(indegree[next] == 0)
                if(next != 1)
                    // 1을 다시 push 할 경우 v[1]에는 더 이상 방문 가능한 node가 없으므로 종료되기 때문에 1을 제외.
                    // 그러나 1로 갔을 경우의 dp 값 비교은 위에서 진행하므로 결과값은 문제 없이 나온다.
                    q.push(next);
        }
    }

    // 최대값 출력
    cout << dp[1] << "\n";

    printLink(1);
    cout << "1\n";      //printLink는 마지막 1을 출력하지 않는다

    return 0;
}