#include<bits/stdc++.h>

using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    sort(a.begin(),a.end(),greater<int>());
    cout << a[k-1];
}
