#include<bits/stdc++.h>

using namespace std;

int main() {
    int n,k,x;
    cin >> n >> k;
    int cnt =0,cnt1=1,res=0,a[n];
    for(int i=0;i<n;++i) cin >>a[i];
    for(int i=0;i<n;++i) {
        if(a[i] == k) {
            cnt += 1;
            if((a[i]==a[i+1]) && (i<n-1)) cnt1 += 1;
            else cnt1 = 1;
            res = max(res,cnt1);
        }
    }
    cout << cnt << '\n' << res;

}
