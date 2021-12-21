#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    long long a,b,n,res;
    cin >> a >> b >> n;
    if(n%2!=0) cout << n*(a+ b*(n-1)/2);
    else cout << (n-1)*(a+b*n/2) + a;

}
