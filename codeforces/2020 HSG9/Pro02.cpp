#include<bits/stdc++.h>

using namespace std;

int main() {
    int n,cnt1,cnt2,cnt3;
    cin >> n;
    cnt1 = n/5;
    n = n%5;
    cnt2 = n/2;
    cnt3 = n%2;
    cout << cnt1 << ' ' << cnt2 << ' ' << cnt3;
}
