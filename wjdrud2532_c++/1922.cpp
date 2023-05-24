#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, MinValue = 0;
vector<pair<int, int> > v[1001];
bool IsVisit[1001];

void prim()
{
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    pq.push(make_pair(0, 1));
    IsVisit[1] = true;

    for(int i = 0; i < N; i ++)
    {
        while (!pq.empty() && IsVisit[pq.top().second])
        {
            pq.pop();
        }

        int next = pq.top().second;
        int cost = pq.top().first;

        IsVisit[next] = true;

        MinValue += cost;

        for(auto& it : v[next])
        {
            pq.push(make_pair(it.second, it.first));
        }

    }

    return;
}

int main()
{
    cin >> N >> M;

    for(int i = 0; i < M; i ++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;

        v[a].push_back(make_pair(b, cost));
        v[b].push_back(make_pair(a, cost));
    }

    prim();

    cout << MinValue << "\n";

    return 0;
}