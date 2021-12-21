#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    vector<long long> a(10001);
    a[0]=0;
    a[1] = 1;
    long long x,i=1;
    while(t) {
        cin >> x;
        bool chk = 0;
        while(x<a[i]) {
            --i;
        }
        while(x>=a[i]) {
            if(x==a[i]) {
                chk = 1;
                break;
            }
            else {
                a[i+1] = a[i] + a[i-1];
                ++i;
            }
        }
        if(chk) cout << "IsFibo";
        else cout << "IsNotFibo";
        cout <<'\n';
        --t;
    }
}
