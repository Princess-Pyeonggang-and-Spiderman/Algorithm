#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<int> v[1001];    //노드
int indegree[1001] = {0,}; //차수

int result[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    int A, B;
    for (int i = 0; i < M; i ++)
    {
        cin >> A >> B;
        v[A].push_back(B);
        //A를 수강해야만 B를 수강할 수 있다

        indegree[B] ++;    //차수 ++
    }

    queue<int> q;

    for (int i = 1; i <= N; i ++) // 차수 범위 1~N
    {
        //차수가 0인 것들 queue에 추가
        //과목을 수강한 것과 같음
        if (indegree[i] == 0)
        {
            q.push(i);
        }

        // 선수과목 개수 초기화
        result[i] = 1;
    }

    //초기값으로 차수가 0인 노드들이 들어있음
    while (! q.empty())
    {
        int current = q.front();
        q.pop();

        // q에 push -> 해당 과목을 수강함
        // 현재 과목을 선수 과목으로 설정한 다른 과목들에 대해 선수과목 개수 -1
        for (int i = 0; i < v[current].size(); i ++)
        {
            int next = v[current][i];
            indegree[next] --;

            // 선수 과목을 모두 이수했다면 수강할 수 있다
            if (indegree[next] == 0)
            {
                q.push(next);

                // 선수 과목 개수는 1부터 시작, 차수가 0이 될 때 현재 선수 과목 개수에 +1
                result[next] = result[current] + 1;
            }
        }
    }

    for(int i = 1; i <= N; i ++)
    {
        cout << result[i] << " ";
    }

    return 0;
}