#include<bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long> fib(n+1);
    fib[0] = 0;
    fib[1] = 1;
    for(int i=2;i<=n;++i) {
        fib[i] = fib[i-1] + fib[i-2];
        if(i==2) cout << fib[1] << ' ';
        cout << fib[i] << ' ';
    }
}
