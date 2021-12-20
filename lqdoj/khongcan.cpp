#include<bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    long long a,b,c;
    cin >> a >> b >>c;
    long long sum = a+b+c;
    if ((sum > 2*a)&&(sum>2*b)&&(sum>2*c)) {
        if ((a == b) || (a == c) || (b == c)) {
            cout << "NO";
        }
        else cout << "YES";
    }
    else cout << "NO";
}
