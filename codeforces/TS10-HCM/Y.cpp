#include<bits/stdc++.h>


using namespace std;

int main() {
    long long n,b,sum=0;
    cin >> n >> b;
    int a[n];
    for(int i=0;i<n;++i) cin >> a[i];
    sort(a,a+n);
    for(long long i=n-1;i>=0;--i) {
        sum += a[i];
        
        if(sum >= b) {
            cout << n-i;
            return 0;
        }
    }
    cout << 0;
}
