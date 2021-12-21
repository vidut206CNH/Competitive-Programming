#include<bits/stdc++.h>

using namespace std;

void solve() {
    long long a,b,c,Max;
    cin >> a >> b >> c;
    if(a+b<=c || b+c <= a || c+a <= b) {
        cout << "NO" << '\n';
        return;
    }
    else {
        Max = max(max(a,b),c);
        if(2*Max*Max == a*a+b*b+c*c ) {
            cout << "NO";
        }
        else cout << "YES";
    }
    cout << '\n';
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin>>T;
    while(T) {
        solve();
        --T;
    }

}
