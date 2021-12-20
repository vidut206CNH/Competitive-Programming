#include<bits/stdc++.h>

using namespace std;

int main() {
    int n,sum=0;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i) cin >>a[i];
    sort(a.begin(),a.end());
    while(a.size()>2) {
        int t = a.size()-1;
        sum += a[t] + a[t-1];
        a.erase(a.begin()+t-2,a.end());
    }
    if(a.size()>0) for(auto x: a) sum += x;
    cout << sum;

}
