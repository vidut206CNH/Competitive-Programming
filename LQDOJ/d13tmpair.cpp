#include<bits/stdc++.h>

using namespace std;

int main() {
    long long n,cnt=1;
    cin >> n;
    for(long long i=2;i*i<=n;++i) {
        if(n%i==0) {
            cnt += 2;
        }
        if(i*i==n) cnt--;
    }
    cout << cnt*2-(n%2==0);

}
