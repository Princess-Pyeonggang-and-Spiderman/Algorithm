// 1707 이분 그래프

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int K;

int V, E;

vector<int> v[20001];
bool isVisit[20001] = { 0, };

int group[20001] = { 0, };

bool isBinary(int startPoint)
{
    queue<int> q;

    q.push(startPoint);
    isVisit[startPoint];
    group[startPoint] = 1;

    while (!q.empty())
    {
        int currentPoint = q.front();
        q.pop();

        int nextGroup;

        (group[currentPoint] == 1) ? nextGroup = 2 : nextGroup = 1;

        for (int i = 0; i < v[currentPoint].size(); i++)
        {
            int nextPoint = v[currentPoint][i];

            // 방문한 경우 건너뜀
            if (isVisit[nextPoint] == true)
                continue;

            q.push(nextPoint);
            isVisit[nextPoint] = true;
            group[nextPoint] = nextGroup;		// 다른 그룹으로 설정
        }

    }

    return true;
}

int main()
{
    cin >> K;

    for (int i = 0; i < K; i++)
    {
        cin >> V >> E;

        for (int j = 0; j < E; j++)
        {
            int num1, num2;
            cin >> num1 >> num2;

            v[num1].push_back(num2);
            v[num2].push_back(num1);
        }

        // 연결되지 않은 모든 트리 탐색
        for (int j = 1; j <= V; j++)
        {
            if (isVisit[j] == false)
            {
                isBinary(j);
            }
        }

        bool isBi = true;
        for (int j = 1; j <= V; j++)
        {
            for (int k = 0; k < v[j].size(); k++)
            {
                // 하나의 정점과 그 정점에 연결된 다른 정점의 그룹을 비교
                if (group[j] == group[v[j][k]])
                {
                    // 서로 연결된 두 정점의 그룹이 같다면 이분 그래프가 아님
                    isBi = false;
                    break;
                }
            }
        }

        if (isBi == true)
            cout << "YES\n";
        else
            cout << "NO\n";

        // 백터 및 방문 초기화
        for (int i = 0; i <= V; i++)
        {
            v[i].clear();
        }
        /*
            v->clear();
		    v->shrink_to_fit();     안됨
         */

        fill_n(isVisit, 20001, false);
        fill_n(group, 20001, 0);

    }

    return 0;
}