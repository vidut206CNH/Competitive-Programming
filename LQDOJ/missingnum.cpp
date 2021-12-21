#include<bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin >> n >> m;
    m = n-m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0;i<n;++i) {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    for(int i=0;i<m;++i) {
        cin >> b[i];
    }
    sort(b.begin(),b.end());
    for(int i=0;i<m;++i) {
        auto x = lower_bound(a.begin(),a.end(),b[i]);
        a.erase(x);
    }
    for(auto x : a) cout << x <<' ';
}
