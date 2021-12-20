
#include<bits/stdc++.h>

using namespace std;
const int MAX = 1e6+1;
long long a[MAX];

int main() {
    memset(a,0,sizeof(a));
    long long n,x,t,res=0;
    cin >> n >> x;
    long long k=x;
    if(x<0) k=0;
    for(int i=0;i<n;++i) {
        cin >> t;
        if(x<0) t -= x;
        if (t<=k&&t>=0) a[t] += 1;
    }
    for(int i=0;i<=k/2;++i) {
        if(k%2 == 0 && i==k/2) res += (a[i]-1)*a[i]/2;
        else res += a[i]*a[k-i];
    }
    cout << res;

}
