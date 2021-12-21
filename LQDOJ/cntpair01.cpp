#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,x,res=0;
    cin >> n;
    vector<int> a(100001,0);
    while(n) {
        cin >> x;
        a[x]++;
        --n;
    }
    for(int i=1;i<100001;++i) {
        if(a[i]>=2) res += (a[i]-1)*a[i]/2;
    }
    cout << res;

}
