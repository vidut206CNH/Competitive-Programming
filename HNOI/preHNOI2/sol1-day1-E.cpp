#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

const int maxN = 2e5 + 10;

int n, m, dist1[maxN], distn[maxN], ans[maxN], color[maxN];
vector <pair <int, int>> adj[maxN];

void bfs(int u, int dist[])
{
    fill(dist + 1, dist + n + 1, -1);
    queue <int> q;
    q.push(u);
    dist[u] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto &e: adj[u])
        {
            int v = e.first;
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    bfs(1, dist1);
    bfs(n, distn);
    fill(ans + 1, ans + n + 1, 1e9);
    fill(color + 1, color + n + 1, 1e9);
    queue <pair <int, int>> q;
    q.push({1, 0});
    while (!q.empty())
    {
        int u = q.front().first;
        int last_color = q.front().second;
        q.pop();
        if (last_color > ans[dist1[u]])
        {
            continue;
        }
        for (auto &e: adj[u])
        {
            int v = e.first, next_color = e.second;
            if (dist1[u] + distn[v] + 1 == dist1[n])
            {
                if (next_color < color[dist1[v]])
                {
                    color[dist1[v]] = next_color;
                    ans[dist1[v]] = min(ans[dist1[v]], next_color);
                    q.push({v, next_color});
                }
            }
        }
    }
    cout << dist1[n] << "\n";
    for (int i = 1; i <= dist1[n]; i++)
    {
        cout << ans[i] << " ";
    }
}