#include <bits/stdc++.h>

using namespace std;

int lcm(int A,int B) {
    return A*B/__gcd(A,B);
}

int cntfactor(int n) {
    int res = 0;
    for(int i=1;i<=sqrt(n);++i) {
        if(n%i==0) {
            res += 2;
        }
        if(i*i == n) res--;
    }
    return res;
}

int main() {
    int n,m;
    cin >> n >> m;
    int LCM,k=n,GCD,x;
    while(k) {
        cin >> x;
        if(k==n) LCM = x;
        LCM = lcm(LCM,x);
        --k;
    }
    k = m;
    while(k) {
        cin >> x;
        if(k==m) GCD = x;
        GCD = __gcd(GCD, x);
        --k;
    }
    if(GCD%LCM != 0) cout << 0;
    else cout << cntfactor(GCD/LCM);
}
