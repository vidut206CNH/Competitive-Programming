#include<bits/stdc++.h>

using namespace std;

int main() {
    int n,mx=0,x;
    cin >> n;
    for (int i=0;i<n;++i) {
        cin >> x;
        if (mx < x) mx = x;
    }
    cout << mx;
}
