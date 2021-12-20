#include<bits/stdc++.h>

using namespace std;

int main() {
    long long n,sumt=0,res=0,x;
    cin >> n;
    for(int i=1;i<=n;++i) {
        cin >> x;
        res += x*sumt;
        sumt += x;
    }
    cout << res;
}
