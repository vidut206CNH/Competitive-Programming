#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;cin >> n;
    int res=0;
    res -= n/2;
    if(n%2 != 0) res += n;
    cout << res;

}
