#include <bits/stdc++.h>

using namespace std;


const int N = 1e5 + 10;

int n, k;
int in[N][2], out[N][2];
int par[N];
vector <int> g[N];

void down(int u, int p) {
    vector <int> child;
    in[u][0] = in[u][1] = 0;
    out[u][0] = out[u][1] = 0;
    for (auto v: g[u]) {
        if (v == p) continue;
        par[v] = u;
        down(v, u);
        child.push_back(v);
    }
    int m = min((int)child.size(), k - 1);
    sort(child.begin(), child.end(), [&](int u, int v) {
        return in[u][0] > in[v][0];
    });
    int tot = 0;
    for (int i = 0; i < m; ++i) tot += in[child[i]][0] + 2;
    for (int i = 0; i < child.size(); ++i) {
        int v = child[i];
        int tmp = (i >= m ? tot + in[v][1] + 1 : (m == child.size() ? tot - (in[v][0] + 2) + (in[v][1] + 1) : tot - in[v][0] + in[v][1] + 1 + in[child[m]][0]));
        in[u][1] = max(in[u][1], tmp);
        if (i < m) in[u][0] += in[v][0] + 2;
    }
    in[u][1] = max(in[u][0], in[u][1]);
}

void up(int u, int p) {
    vector <tuple <int, int, int> > child;
    if (p) child.push_back({out[u][0], out[u][1], p});
    for (auto v: g[u]) {
        if (v == p) continue;
        child.push_back({in[v][0], in[v][1], v});
    }
    sort(child.begin(), child.end(), greater<>());
    int m = min((int)child.size(), k - 1);
    int tot = 0;
    for (int i = 0; i < m; ++i) tot += get<0>(child[i]) + 2;

    for (int i = 0; i < child.size(); ++i) {
        int v = get<2>(child[i]);
        if (v == p) continue;
        if (i >= m) out[v][0] = tot;
        else out[v][0] = tot - (get<0>(child[i]) + 2) + (m < child.size() ? get<0>(child[m]) + 2 : 0);
    }
    int tmp[2][3];
    memset(tmp, - 60, sizeof(tmp));
    for (int i = 0; i < child.size(); ++i) {
        int v = get<2>(child[i]);
        if (i > m) {
            int cur = tot + get<1>(child[i]) + 1;
            tmp[1][2] = cur;
            sort(tmp[1], tmp[1] + 3, greater<>());
        } else {
            int cur = (m == child.size() ? tot - (get<0>(child[i]) + 2) + (get<1>(child[i]) + 1) : tot - get<0>(child[i]) + get<1>(child[i]) + 1 + get<0>(child[m]));
            tmp[0][2] = cur;
            sort(tmp[0], tmp[0] + 3, greater<>());
        }
    }
    for (int i = 0; i < child.size(); ++i) {
        int v = get<2>(child[i]);
        if (v == p) continue;
        if (i > m) {
            out[v][1] = tmp[0][0];
            int cur = tot + get<1>(child[i]) + 1;
            if (cur == tmp[1][0]) out[v][1] = max(out[v][1], tmp[1][1]);
            else out[v][1] = max(out[v][1], tmp[1][0]);
        } else {
            int cur = (m == child.size() ? tot - (get<0>(child[i]) + 2) + (get<1>(child[i]) + 1) : tot - get<0>(child[i]) + get<1>(child[i]) + 1 + get<0>(child[m]));
            if (cur == tmp[0][0]) out[v][1] = max(out[v][1], tmp[0][1] - (get<0>(child[i]) + 2) + (m + 1 < child.size() ? get<0>(child[m + 1]) + 2 : 0));
            else out[v][1] = max(out[v][1], tmp[0][0] - (get<0>(child[i]) + 2) + (m + 1 < child.size() ? get<0>(child[m + 1]) + 2 : 0));
        }
        out[v][1] = max(out[v][1], out[v][0]);
    }
    for (auto v: g[u]) if (v != p) up(v, u);
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    down(1, 0);
    up(1, 0);
    int ans = 0;
    for (int u = 1; u <= n; ++u) {
        vector <pair <int, int> > s;
        if (u != 1) s.push_back({out[u][0], out[u][1]});
        for (auto v: g[u]) {
            if (v == par[u]) continue;
            s.push_back({in[v][0], in[v][1]});
        }
        int tot = 0;
        sort(s.begin(), s.end(), greater<>());
        int m = min(k - 1, (int)s.size());
        for (int i = 0; i < m; ++i) tot += s[i].first + 2;
        ans = max(ans, tot);
        for (int i = 0; i < s.size(); ++i) {
            int tmp = (i >= m ? tot + s[i].second + 1 : (m == s.size() ? tot - (s[i].first + 2) + (s[i].second + 1) : tot - s[i].first + s[i].second + 1 + s[m].first));
            ans = max(ans, tmp);
        }
    }
    cout << ans * 10 << '\n';
    for (int i = 1; i <= n; ++i) g[i].clear();
}

int main() {
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) solve();
}