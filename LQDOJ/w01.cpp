#include<bits/stdc++.h>

using namespace std;

int main() {
    long long x,sum=0;
    while (cin >> x) {
        if (x == 0) {
            break;
        }
        else sum = sum + x;
    }
    cout << sum;
}
