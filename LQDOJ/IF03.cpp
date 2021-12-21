#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

long MIN(long a, long b) {
    long MIN = a;
    if (a>b) {
        MIN = b;
    }
    return MIN;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long a,b,c,d;
    cin >> a >> b >> c >> d;
    cout << MIN(MIN(a,b),MIN(c,d));
}
