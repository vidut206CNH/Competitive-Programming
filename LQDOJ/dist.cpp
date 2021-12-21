#include<bits/stdc++.h>

using namespace std;

int main() {
    int n,cnt=0;
    cin >> n;
    vector<long long> a(n);
    for(int i=0;i<n;++i) cin >> a[i];
    sort(a.begin(),a.end());
    for(int i=0;i<n;++i) {
        if(a[i]!=a[i-1] || i==0) cnt++;
    }
    cout << cnt;

}
