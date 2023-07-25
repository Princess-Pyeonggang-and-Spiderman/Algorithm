//13913 숨바꼭질 4

#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

int dist[100001] = { 0 };
int n, k;
int ans;
int memo[100001];

vector<int> path;

bool visited[100001] = { false };

void bfs()
{
    q.push(n);
    visited[n] = true;
    while (!q.empty())
    {
        int n = q.front();
        q.pop();
        int go[3] = { n - 1, n + 1, 2 * n };
        for (int i = 0; i < 3; i++)
        {
            int nx = go[i];
            if (0 <= nx && nx <= 100000 && !visited[nx])
            {
                q.push(nx);
                visited[nx] = true;
                dist[nx] = dist[n] + 1;
                memo[nx] = n;
            }
            if (nx == k) {
                ans = dist[nx];
                return;
            }
        }
    }

    return;
}

int main(void)
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    if (n == k)
    {
        cout << '0' << '\n' << n;
    }
    else {
        bfs();
        cout << ans << '\n';
        path.push_back(k);
        for (int i = 0; i < ans; i++)
        {
            path.push_back(memo[k]);
            k = memo[k];
        }
        for (int i = path.size() - 1; i >= 0; i--)
            cout << path[i] << ' ';
    }

    return 0;
}