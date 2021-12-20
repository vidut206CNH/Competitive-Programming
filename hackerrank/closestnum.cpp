#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    int minz = 1e5,x;
    cin >> n;
    vector<int> vec;
    int a[n];
    for(int i=0;i<n;++i) cin >> a[i];
    sort(a,a+n);
    for(int i=0;i<n-1;++i) {
        x = abs(a[i]-a[i+1]);
        if (x<minz) {
            vec.clear();
            minz = x;
            vec.push_back(a[i]);
            vec.push_back(a[i+1]);
        }
        else if(x == minz) {
            vec.push_back(a[i]);
            vec.push_back(a[i+1]);
        }
    }
    for(auto x : vec) cout << x << ' ';
}

int main() {
    solve();


}
