#include<bits/stdc++.h>

using namespace std;

void solve() {
    long long n,k;
    cin >> n >> k;
    if (k%(n-1)==0)cout << n*((k/(n-1))-1) + (n-1);
    else cout << n*(k/(n-1)) + k%(n-1);
    cout << endl;
}


int main() {
    int q;
    cin >> q;
    while(q) {
        solve();
        --q;
    }
}
