#include<bits/stdc++.h>

using namespace std;

int main() {
    string a,b;
    getline(cin, a);
    getline(cin, b);
    int res = (a.size()-b.size());
    if (res<0) cout << -res;
    else cout << res;
}
