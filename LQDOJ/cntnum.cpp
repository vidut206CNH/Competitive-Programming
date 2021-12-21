#include<bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    int x,cnt1=0,cnt2=0;
    while(n--) {
        cin >> x;
        if(x<0) cnt1 += 1;
        if(x>0) cnt2 += 1;
    }
    cout << cnt1 << ' ' << cnt2;
}
