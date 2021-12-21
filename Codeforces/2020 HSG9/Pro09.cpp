#include<bits/stdc++.h>

using namespace std;

int main() {
    int n,res=0;
    cin >> n;
    int a[n];
    for(int i=0;i<n;++i) cin >> a[i];
    sort(a,a+n);
    int cnt = 1;
    for(int i=0;i<n-1;++i) {
        if(a[i] == a[i+1]) cnt += 1;
        else {
            res += cnt/2;
            cnt = 1;
        }
    }
    res += cnt/2;
    cout << res;

}
