#include<bits/stdc++.h>

using namespace std;

bool sortvec(const vector<int> &a,const vector<int> &b) {
    if(a[0]==b[0]) return (a[1] < b[1]);
    return (a[0]>b[0]);
}

int main() {
    int n,k,sum=0;
    cin >> n >> k;
    vector< vector<int> > a(n);
    for(int i=0;i<n;++i) {
        a[i].resize(2);
        cin >> a[i][1] >> a[i][0];
    }
    sort(a.begin(),a.end(),sortvec);
    for(int i=0;i<n;++i) {
        if(k >= a[i][1]) {
            sum += a[i][0];
            k -= a[i][1];
        }
        if(i==n-1) break;
    }
    cout << sum;



}
