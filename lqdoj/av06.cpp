#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;++i) cin >> arr[i];
    for (int i=0;i<n;++i) {
        if (arr[i]<0) {
            cout << i+1 <<' ';
            break;
        }
        if(i==n-1) {
            cout << -1 << ' ' << -1;
            return 0;
        }
    }
    for(int i=n-1;i>=0;--i) {
        if (arr[i]<0) {
            cout << i+1;
            return 0;
        }
    }
}
