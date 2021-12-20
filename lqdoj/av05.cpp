#include<bits/stdc++.h>

using namespace std;

int main() {
    int n,x=0;
    cin >> n;
    long long arr[n];
    for (int i=0;i<n;++i) cin >> arr[i];
    for (int i=0;i<n;++i) {
        if (arr[i]>0) {
            cout << i+1 << " ";
            ++x;
            break;
        }
        if (i == n-1) cout << -1 << " " << -1;
    }
    if (x == 1) {
        for (int i=n-1;i>=0;--i) {
            if (arr[i]>0) {
                cout << i + 1;
                break;
            }
        }
    }
}
