#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, ans = -1e6, res = -1e6, sum = 0;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum = max(a[i], sum + a[i]);
        res = max(max(res + a[i], res), a[i]);
        ans = max(sum, ans);
    }
    cout << ans << ' ' << res << '\n';
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t) {
        solve();
        --t;
    }
}