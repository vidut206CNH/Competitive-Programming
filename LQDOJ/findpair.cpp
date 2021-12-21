#include<bits/stdc++.h>

using namespace std;

int main() {
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i=0;i<n;++i) cin >> a[i];
    int i=0,j=n-1;
    while(i<j) {
        if(a[i]+a[j]<x) ++i;
        if(a[i]+a[j]>x) --j;
        if(a[i]+a[j]==x) {
            cout << i+1 << ' ' << j+1;
            return 0;
        }
    }
    cout << "No solution";
}
