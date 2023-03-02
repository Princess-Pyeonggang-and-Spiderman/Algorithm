#include <iostream>
#include <type_traits>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<pair<int, int>> v[1001];
int indegree[1001] = {0, };
int dp[1001];

// 1을 가장 마지막에 저장
// 가장 큰 값을 어디서 가져왔는지 기록

// resultList[1] 은 이전에 가장 큰 값 4를 가리킴
// resultList[4] 는 7 ... 이런식으로 저장
int resultList[1001] = {0, };

//32
//1 2 5 6 8 7 4 1

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    int start, end, value;
    for(int i = 0; i < M; i ++)
    {
        cin >> start >> end >> value;

        indegree[end] ++;   // 이곳에 도달할 수 있는 방법의 수

        // 출발지            도착지  점수
        v[start].push_back({end, value});
    }

    queue<int> q;
//    for(int i = 0; i < v[1].size(); i ++)
//    //for(int i = 1; i <= N; i ++)
//    {
//        q.push(v[1][i]);
//        dp[q.front().first][0] = q.front().second;
//    }

    q.push(1);

    // 예제대로 가면 지금 2, 3 이 queue에 들어가 있음
    while(!q.empty())
    {
        int current = q.front();
        q.pop();

        for(int i = 0; i < v[current].size(); i ++)
        {
            int next = v[current][i].first;
            indegree[next] --;

            if(dp[current] + v[current][i].second > dp[next])
            {
                dp[next] = dp[current] + v[current][i].second;
                resultList[current] = next;
            }

            // value -> second

            // 현재 next 에서 갖고 있는 값과 새로운 값을 비교하여
            // 더 큰 값을 next에 저장
            // 어디에서 가져왔는지를 list에 저장해야함

            //dp 해야함
            //이 곳과 연결될 수 있는 모든 값들 중에서 가장 큰 값을 찾는다.
            //next에 해당되는 vector에 값을 push?

            //-> --하는 것은 연결되어 있는 무언가를 처리한 것이므로
            // --할 때 마다 현재 갖고 있는 값보다 크다면 그것이
            // 현재 노드에서 가질 수 있는 가장 큰 값이 된다.

            if(indegree[next] == 0)
            {
                q.push(next);


            }
        }
    }
    /*
     해당 좌표가 가질 수 있는 최대값,
     이 것과 연결될 수 있는 것들 중 가장 큰 것을 선택
     */

    for(int i = 0; i <= N; i ++)
    {
        cout << dp[i] << " ";
    }

    cout << "\n";

    for(int i = 0; i <= N; i ++)
    {
        cout << resultList[i] << " ";
    }


}
