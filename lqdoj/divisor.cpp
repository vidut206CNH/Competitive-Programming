#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    int sum=0,cnt=0;
    cin >> n;
    for(int i=1;i<=sqrt(n);++i) {
        if(n%i==0) {
            if(i*i == n) {
                cnt += 1;
                sum += i;
            }
            else {
                cnt = cnt +2;
                sum += (i+ n/i);
            }
        }
    }
    cout << cnt << ' ' << sum;
}
