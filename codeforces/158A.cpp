#include<bits/stdc++.h>

using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;++i) cin >> a[i];
    if(a[k-1]>0) {
        for(int i=k;i<n;++i) {
            if(a[i] != a[i-1]) break;
            ++k;
        }
        cout << k;
        return 0;
    }
    else {
        if(a[0]==0) {
            cout << 0;
            return 0;
        }
        for(int i=k-1;i>=0;--i) {
            if(a[i] != 0) break;
            --k;
        }
        cout << k;
    }

}
