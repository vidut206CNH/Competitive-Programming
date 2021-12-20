#include<bits/stdc++.h>

using namespace std;

int bins(int k) {
    k = k / 5 * 2;
    int t = sqrt(k);
    while (t * (t + 1) > k) {
        --t;
    }
    return t;
}

int main() {
    int n, k;
    cin >> n >> k;
    k = 240 - k;
    if (k < 5) {
        cout << 0;
        return 0;
    }
    cout << min(bins(k), n);
}