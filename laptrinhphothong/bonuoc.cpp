#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin>>n;
    int cnt1=0,res=0,cnt2=0;
    if(n%2==0) cnt2++;
    while(n%2==0) {
       cnt1++;
       n /= 2;
    }
    if(cnt1>=3) res++;
    for(int i=3;i<=sqrt(n);++i) {
        if(n%i==0) {
            cnt2++;
            int temp=0;
            while(n%i==0) {
                temp++;
                n /= i;
            }
            if(temp>=3) res++;
        }
    }
    if(n>2) cnt2++;
    res += cnt2*(cnt2-1)/2;
    cout <<res;
}

int main() {
    solve();

}
