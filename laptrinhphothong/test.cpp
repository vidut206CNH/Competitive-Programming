#include<bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;
    n *= 2;
    for(int i=1;i<=sqrt(n);++i) {
        if(n%i==0 && (n/i - i==1)) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}
