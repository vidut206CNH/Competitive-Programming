#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;


int main() {
    int n,k,temp;
    cin >> n >> k;

    vector<int> vec(n);
    for(auto &x : vec) cin >> x;


    vector<int> dp(n);
    dp[0] = 0;
    dp[1] = abs(vec[1] - vec[0]);
    for(int i=2;i<n;++i) {
        if (i>=k) {
            for(int j=1;j<=k;++j) {
                dp[i] = dp[i-j] + abs(vec[i]- vec[i-j]);
                if(j==1) temp = dp[i];
                temp = min(dp[i], temp);


            }
        }
        else {
            for(int j=1;j<=i;++j) {
                dp[i] = dp[i-j] + abs(vec[i]- vec[i-j]);
                if(j==1) temp = dp[i];
                temp = min(dp[i], temp);
            }
        }
        dp[i] = temp;
    }
    cout << dp.back();
}
