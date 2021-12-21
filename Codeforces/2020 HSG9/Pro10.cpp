#include<bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;
    cout << (n*n)/2;
    if(n%2 == 0) cout << ".0";
    else cout << ".5";
}
