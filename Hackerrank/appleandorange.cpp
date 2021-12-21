#include<bits/stdc++.h>

using namespace std;

int main() {
    int s,t,a,b,m,n,d,cnt1=0,cnt2=0;
    cin >> s >> t >> a >> b >> m >> n;
    while(m) {
        cin >> d;
        if(d>=(s-a)&&d<=(t-a)) cnt1 += 1;
        --m;
    }
    while(n) {
        cin >> d;
        if(d<=(t-b)&&d>=(s-b)) cnt2 +=1;
        --n;
    }
    cout << cnt1 << '\n' << cnt2;

}
