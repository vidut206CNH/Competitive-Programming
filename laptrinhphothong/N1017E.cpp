#include<bits/stdc++.h>
#pragma GCC optimize("O1")
using namespace std;

const long long mod = 1000000007;

long long pows(long long a,long long b) {
    long long res=1,ai=a;
    while(b) {
        if(b%2!=0) {
            res = ((res%mod)*(ai%mod))%mod;
        }
        ai = ((ai%mod)*(ai%mod))%mod;
        b /= 2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    unsigned long long k,a,b,Min,res;
    cin >> k >> a >> b;
    k %= mod;
    Min = min(a, b);
    if(k==1 || Min==0) {
        cout << 1;
        return 0;
    }
    if(Min==1 || Min==2) {
        cout << k-1;
        return 0;
    }
    vector<unsigned long long> dp(Min+1);
    dp[0] = 1;
    dp[1] = k;
    dp[2] = k;
    for(long long i=3;i<=Min;++i) {
        dp[i] = ((dp[i-1]%mod)*(dp[i-2]%mod))%mod;
    }
    cout << dp[Min]-1;
}
