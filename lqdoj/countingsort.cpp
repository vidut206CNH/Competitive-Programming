#include<bits/stdc++.h>

using namespace std;
int arrc[100];
int main() {
    int n,x;
    cin >> n;
    for(int i=0;i<n;++i) {
        cin >> x;
        arrc[x] += 1;
    }
    for(int i=0;i<100;++i) {
        cout << arrc[i] << ' ';
    }
}
