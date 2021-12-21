#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;cin >> n;
    long long a=0,b=1,c=1;
    for(int i=0;i<n;++i) {
        cout << c << ' ';
        c = a+b;
        a = b;
        b = c;
    }

}
