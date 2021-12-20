#include<bits/stdc++.h>

using namespace std;

int main() {
    int n,k,x,sum=0,x1;
    cin>>n>>k;
    vector<int> a;
    for(int i=0;i<n;++i) {
        cin>> x;
        if(x<0) {
            x1 = -x;
            a.push_back(x1);
        }
    }
    sort(a.begin(),a.end(),greater<int>());
    for(int i=0;i<k;++i) {
        if(i==a.size()) break;
        sum += a[i];
    }
    cout << sum;
}
