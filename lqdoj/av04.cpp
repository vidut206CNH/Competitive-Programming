#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long value,sum=0,cnt=0;
    while(n != 0) {
        cin >> value;
        if (value<0) {
            sum += value;
            cnt += 1;
        }
        --n;
    }
    if (sum == 0) cout << -1;
    else cout << fixed << setprecision(2) << (double)sum/cnt;
}
