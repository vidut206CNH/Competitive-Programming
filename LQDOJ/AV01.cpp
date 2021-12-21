#include<bits/stdc++.h>

using namespace std;

#define upto(n) for(int i=0;i<n;++i)

int main() {
    int N;
    long long a,sum=0;
    cin >> N;
    upto(N) {
        cin >> a;
        if (a%2 == 0) {
            sum += a;
        }
    }
    cout << sum;

}
