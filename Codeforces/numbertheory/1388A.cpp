#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n < 31) {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES\n";
    if (n != 36 && n != 40 && n != 44) {
        cout << 6 << ' ' << 10 << ' ' << 14 << ' ' << n - 30 << '\n';
    }
    else cout << 6 << ' ' << 10 << ' ' << 15 << ' ' << n - 31 << '\n';
}


int main() {
    int t;
    cin >> t;
    while (t) {
        solve();
        --t;
    }
}