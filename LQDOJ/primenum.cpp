#include<bits/stdc++.h>

using namespace std;

int main() {
    long long a,b;
    cin>>a>>b;
    vector<bool> ar(b+1 ,true);
    ar[0]=false;ar[1]=false;
    for(long long i=2;i*i<=b;++i) {
        if(ar[i]) {
            for(long long j=i*2;j<=b;j += i) {
                ar[j] = false;
            }
        }
    }
    for(long long j=a;j<=b;++j) {
        if(ar[j]) {
            cout << j << '\n';
        }
    }
}
