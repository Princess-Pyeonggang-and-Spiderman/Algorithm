#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //cout << "start\n";

    int N, M, caseCnt = 1;

    while (1)
    {
        cin >> N >> M;

        if (N == 0 && M == 0)
            break;

        //트리, 방문 초기화
        vector<int> v[501];
        bool isVisit[501] = {0,};
        int treeCnt = 0;

        //정점 입력, 트리 연결
        int node1, node2;
        for (int i = 0; i < M; i++)
        {
            cin >> node1 >> node2;

            v[node1].push_back(node2);
            v[node2].push_back(node1);
        }

        //트리 탐색
        for (int i = 1; i <= N; i++)
        {
            bool isTree = true;

            //연결된 노드가 없는 경우 독립적인 하나의 트리로 취급
            if (v[i].empty())
            {
                treeCnt ++;
                continue;
            }

            queue<int> q;
            q.push(i);

            while (!q.empty())
            {
                int currentNode = q.front();
                q.pop();

                if (isVisit[currentNode] == true)
                    isTree = false;
                else
                    isVisit[currentNode] = true;

                //연결된 노드가 있을 경우 노드를 따라 방문 여부 확인(
                for (int j = 0; j < v[currentNode].size(); j++)
                    if(!isVisit[v[currentNode][j]])
                        q.push(v[currentNode][j]);
            }

            if (isTree)
                treeCnt++;
        }

        //트리 결과 출력
        cout << "Case " << caseCnt ++ << ": ";

        if (treeCnt == 1)
            cout << "There is one tree.\n";
        else if (treeCnt == 0)
            cout << "No trees.\n";
        else
            cout << "A forest of " << treeCnt << " trees." << "\n";
    }

    return 0;
}