#include<bits/stdc++.h>

using namespace std;

int main() {
    int n,k;cin >> n >> k;
    int t = n/k + 1,sum=1,i=1;
    while(t>=pow(2,i)) {
        ++i;
    }
    i -= 1;
    if(t>pow(2,i) || n%k!=0) ++i;
    cout << i;
}
