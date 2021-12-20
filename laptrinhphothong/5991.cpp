#include<bits/stdc++.h>
#pragma GCC optimize("O1")
using namespace std;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n;
    cin >> n;
    vector<long long> a(n);
    for(int i=0;i<n;++i) cin >> a[i];
    sort(a.begin(),a.end());
    for(int i=0;i<n;++i) {
        if(a[i]%2) cout << a[i] << ' ';
    }
    cout << '\n';
    sort(a.begin(),a.end(),greater<long long>());
    for(int i=0;i<n;++i) {
        if(a[i]%2==0) cout << a[i] << ' ';
    }

}
