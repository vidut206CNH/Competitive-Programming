#include<bits/stdc++.h>

using namespace std;


void slt(int n) {
    bool prime[n+1];
    int cnt = 0;
    memset(prime,true,sizeof(prime));
    for (int i=2;i*i<=n;++i) {
        if (prime[i] == true) {
            for (int t=i*i;t<=n; t += i) {
                prime[t] = false;
            }
        }
    }
    for (int i=3;i<=(n/2);i += 2) {
        if ((prime[i]) && (prime[n-i])) {
            cnt += 1;
        }
    }
    cout << cnt;
}

int main() {
    int n;
    cin >> n;
    slt(n);
}
