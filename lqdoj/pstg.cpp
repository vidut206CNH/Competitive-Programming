#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

void solve(long long n) {
    long long res=n;
    if(n%2 == 0) res /= 2;
    while(n%2==0 && n>1) {
        n /= 2;
    }
    for(int i=3;i<=sqrt(n);i += 2) {
        if(n%i==0) {
            res /= i;
            res *= (i-1);
            while(n%i==0) {
                n /= i;
            }
        }
    }
    if(n>2) {
        res /= n;
        res *= (n-1);
    }
    cout << res;
}


int main() {
    long long n;
    cin >> n;
    solve(n);
}
