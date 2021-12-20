#include<bits/stdc++.h>

using namespace std;

int main() {
    double n,sum=1;
    int i=2;
    cin >> n;
    while(sum <= n) {
        sum += 1.0/i;
        ++i;
    }
    cout << i-1;
}
