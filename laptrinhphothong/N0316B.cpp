#include<bits/stdc++.h>

using namespace std;


void sieveE(int n,bool a[]) {
    memset(a,1,sizeof(a));
    for(int i=2;i*i<=n;++i) {
        if(a[i]) {
            for(int j=2*i;j<=n;j += i) {
                a[j] = 0;
            }
        }
    }
    a[0] = 0;
    a[1] = 0;
}

int main() {
    int a,b;
    bool chk=0;
    cin >> a >> b;
    bool ar[b+1];
    memset(ar,1,sizeof(ar));
    sieveE(b,ar);
    for(int i=a;i<=b;++i) {
        if(ar[i]) {
            cout << i << ' ';
            chk = 1;
        }
    }
    if(!chk) cout << -1;

}


