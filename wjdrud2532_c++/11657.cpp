//11657 타임머신

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 2100000000

int N, M, x, y, z;
long long dist[501];
bool cycle;

vector <pair <int, int>> edge[501];

void bellman_ford() {
    fill(dist, dist + N + 1, INF);
    dist[1] = 0;

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < edge[i].size(); j++) {
                int next = edge[i][j].first;
                int nextcost = edge[i][j].second;

                if (dist[i] != INF && dist[next] > dist[i] + nextcost) {
                    dist[next] = dist[i] + nextcost;
                    if (k == N) cycle = true;
                }
            }
        }
    }
    if (cycle) cout << -1;
    else {
        for (int i = 2; i <= N; i++)

            cout << (dist[i] != INF ? dist[i] : -1) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> x >> y >> z;
        edge[x].push_back({ y, z });
    }
    bellman_ford();
}