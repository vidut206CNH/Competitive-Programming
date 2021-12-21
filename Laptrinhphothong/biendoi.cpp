#include<bits/stdc++.h>

using namespace std;

int main() {
    int n,cnt2=0,res,cnt=0;
    cin >> n;
    while(n>1) {
        if(n%2 != 0) break;
        if(n%6==0) {
            ++cnt;
            n /= 6;
        }
        else if (n%2 == 0) {
            ++cnt2;
            n /= 2;
        }
    }
    if((cnt==0 && cnt2 ==0) || (n>1)) {
        cout << -1;
    }
    else {
        res = cnt + cnt2*2;
        cout << res;
    }



}
