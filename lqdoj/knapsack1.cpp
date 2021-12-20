#include<bits/stdc++.h>

using namespace std;
const long long Max = 1e5;
void solve() {
    long long n, w;
    cin >> n >> w;
    w = min(w, Max);
    vector<long long> dp(w + 1, 0), we(n + 1), va(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> we[i] >> va[i];
        for (int k = w; k >= we[i]; --k) {
            dp[k] = max(dp[k], dp[k - we[i]] + va[i]);
        }
    }
    cout << dp[w];
}


int main() {
    solve();
}