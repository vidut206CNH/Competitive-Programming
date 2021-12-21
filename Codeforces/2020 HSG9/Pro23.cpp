#include<bits/stdc++.h>

using namespace std;

bool binarySearch(vector<int> a,int k) {
    int lo = 0,hi = a.size()-1;
    while(lo<=hi) {
        int mi = (lo+hi)/2;
        if(k==a[mi]) {
            return 1;
        }
        if(k>a[mi]) {
            lo = mi + 1;
        }
        else hi = mi-1;
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i) cin >>a[i];
    sort(a.begin(),a.end());
    for(int i=1;i<=n;++i) cout << a[i] << ' ';
    cout << '\n';
    vector<bool> prime(1001,1);
    prime[0] = 0;
    prime[1] = 0;
    for(int i=2;i*i<=1001;++i) {
        if(prime[i]) {
            for(int j=2*i;j<=1001;j += i) {
                prime[j] = 0;
            }
        }
    }
    int k=2;
    for(int i=1;i<=n;++i) {
        while(k<a[i]) {
            if(prime[k]) {
                cout << k;
                return 0;
            }
            ++k;
        }
        k = a[i]+1;
    }
    for(int i=a[n]+1;i<=1000;i += 2) {
        if(prime[i]) {
            cout << i;
            return 0;
        }
    }
}
