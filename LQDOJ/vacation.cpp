#include<bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    int a[n],b[n],c[n];
    for(int i=0;i<n;++i) {
        cin >> a[i] >> b[i] >> c[i];
    }
    for(int i=1;i<n;++i) {
        a[i] += max(b[i-1], c[i-1]);
        b[i] += max(a[i-1], c[i-1]);
        c[i] += max(a[i-1], b[i-1]);
    }
    cout << max(a[n-1],max(b[n-1],c[n-1]));

}
