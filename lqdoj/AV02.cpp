#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    long long a,sum=0;
    cin >> N;
    for (int i=1;i<=N;++i) {
        cin >> a;
        if (a%2 != 0) {
            sum += a;
        }
    }
    cout << sum;
}
