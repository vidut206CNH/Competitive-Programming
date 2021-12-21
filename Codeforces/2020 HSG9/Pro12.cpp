#include<bits/stdc++.h>
#pragma GCC optimize("O1")
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,cnt1=0,st=0,mlen=0,st1=1;
    long long sum=0,ave;
    bool chk=0;
    cin >> n;
    vector<ll> a(n);
    vector<ll> sumz(n);
    for(int i=0;i<n;++i) {
        cin >> a[i];
        if((a[i]%3==0) &&(a[i]%2!=0)) cnt1 += 1;
        if(a[i]>0) chk = 1;
        sum += a[i];
        sumz[i] = sum;
        if(sumz[i]>0) {
            mlen = i+1;
        }
    }
    long long res=1e9+7,res1=0;
    for(int i=0;i<n;++i) {
        if(a[i]*n>sum && a[i]<res) {
            res = a[i];
            res1 = i+1;
        }
    }
    cout << cnt1 << '\n' << res1 << '\n';
    if(chk==0) {
        cout << -1;
        return 0;
    }
    ++st;
    while(st+mlen<n) {
        for(int j=st+mlen;j<n;++j) {
            long long temp = sumz[j] - sumz[st-1];
            if(temp>0) {
                st1 = st+1;
                mlen = j-st+1;
            }
        }
        ++st;
    }
    if(mlen!=0) cout << st1 << ' ' << st1+mlen-1;
    else cout << -1;
    return 0;
}
