#include<bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,sum=0;
    cin >> n;
    for (int i=2;i<=sqrt(n);++i) {
        if (n%i == 0) {
            if (n/i == i) {
                sum = sum + i;
            }
            else {
                sum = sum + i + n/i;
            }
        }
    }
    if (sum == n - 1) {cout << "YES";}
    else cout << "NO";
}
