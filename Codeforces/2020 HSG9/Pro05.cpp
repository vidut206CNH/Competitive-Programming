#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, res = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size() - 1; ++i) {
        if (a[i] == a[i + 1]) {
            a.erase(a.begin() + i);
            --i;
        }
    }

    for (int i = 0; i < a.size() - 2; ++i) {
        res = max(res, abs(a[i] + a[i + 1] + a[i + 2]));
    }
    cout << res;
}
