#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if(b==0) return a;
    else return gcd(b,a%b);
}

int main() {
    int n,p,t,cnt=1;
    cin >> n >> p;
    t=n/p;
    if(n%p == 0) {
        for(int i=2;i<t;++i) {
            if(gcd(t,i)==1) cnt+=1;
        }
    }
    else cnt = 0;
    cout << cnt;

}
