#include<bits/stdc++.h>

using namespace std;
#define mod 1000000007
int main() {
    int n;
    cin >> n;
    long long a=0,b=1,c=1;
    for(int i=1;i<=n;++i) {
        if(i==n) cout << c;
        c = (a%mod+b%mod)%mod;
        a = b%mod;
        b = c%mod;
    }
}
