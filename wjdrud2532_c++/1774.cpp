#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int N, M;
long double MinValue = 0.0;
vector<pair<double, double> > v[1000001];
bool IsVisit[1000001];
pair<int, int> p[1000001];

void prim()
{
    priority_queue<pair<double, double>, vector<pair<double, double> >, greater<pair<double, double> > > pq;

    //한 지점에 대해 모든 점의 거리를 계산

    //시작 전에 방문 초기화
    fill_n(IsVisit, 1000001, false);

    //비용, 위치
    pq.push(make_pair(0, 1));
    IsVisit[1] = true;

    for(int i = 0; i < N; i ++)
    {
        while (!pq.empty() && IsVisit[(int)pq.top().second])
        {
            pq.pop();
        }

        int next = pq.top().second;
        double cost = pq.top().first;

        IsVisit[next] = true;

        MinValue += cost;

        //cout << next << " " << cost << "\n";

        for(auto& it : v[next])
        {
            pq.push(make_pair(it.second, it.first));
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M;

    //모든 노드의 좌표를 입력 받는다
    for(int i = 1; i <= N; i ++)
    {
        int a, b;
        cin >> a >> b;
        p[i] = make_pair(a, b);
    }

    //연결된 노드들의 비용은 0
    //방문처리한다
    for(int i = 0; i < M; i ++)
    {
        int a, b;
        cin >> a >> b;

        v[a].push_back(make_pair(b, 0));
        v[b].push_back(make_pair(a, 0));

        //IsVisit[a] = IsVisit[b] = true;
    }

    for(int i = 1; i <= N; i ++)
    {
//        if(IsVisit[i])
//            continue;

        for(int j = 1; j <= N; j ++)
        {
            long long int a, b;
            long double cost;
            a = pow(p[i].first - p[j].first, 2);
            b = pow(p[i].second - p[j].second, 2);
            cost = sqrt(a + b);

            v[i].push_back(make_pair(j, cost));
            v[j].push_back(make_pair(i, cost));
        }
    }

//    for(int i = 1; i <= N; i ++)
//    {
//        for(int j = 0; j < v[i].size(); j++)
//        {
//            cout << v[i][j].first << " " << v[i][j].second << " ";
//        }
//        cout << "\n";
//    }

    prim();

    //셋째자리 반올림 후 둘째자리까지 출력
    cout << fixed;
    cout.precision(2);
    cout << MinValue << "\n";

    return 0;
}