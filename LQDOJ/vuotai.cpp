#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    long long n,k,res = 1,MAX=0;
    cin >> n >> k;
    while(n>0) {
        long long x;
        cin >> x;
        res += x;
        MAX = max(MAX,x);
        --n;
    }
    res -= min(MAX, k);
    cout << res;

}
