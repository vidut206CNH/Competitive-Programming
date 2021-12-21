#include<bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long> arr(n+1);
    for(long long i=1;i<=n;++i) {
        cin >> arr[i];
        if(i > arr[i]) {
            cout << -1;
            return 0;
        }
    }
    int start = 0;
    for(long long i=1;i<=n;++i) {
        if(arr[i] != arr[i-1] && i>1) {
            cout << 1 << ' ';
        }
        else {
            cout << i-start << ' ';
        }
        if(arr[i] == i) {
            start = i;
        }
    }
}
