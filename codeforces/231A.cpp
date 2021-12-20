#include<bits/stdc++.h>

using namespace std;

int main() {
    int n,cnt=0;
    cin >> n;
    while(n) {
        int sum=0,x;
        for(int i=1;i<=3;++i) {
            cin >> x;
            sum += x;
        }
        if(sum>1) cnt++;
        --n;
    }
    cout << cnt;
}
