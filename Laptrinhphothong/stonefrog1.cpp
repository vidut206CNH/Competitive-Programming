#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;


    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<int> dp(n,0);
    for(int i=1;i<n;++i) {
        dp[i] = dp[i-1] + abs(a[i] - a[i-1]);
        if(i>= 2) {
            dp[i] = min(dp[i], dp[i-2] + abs(a[i]-a[i-2]));
        }
    }
    cout << dp.back();
}
