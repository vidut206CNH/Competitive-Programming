#include<bits/stdc++.h>
#pragma GCC optimize("O1")

bool arr[10000000];

using namespace std;

bool prime(long long b) {
    if ((b == 1) || (b==0)) return 0;
    if ((b==2) || (b==3)) {
        arr[b] = true;
        return 1;
    }
    else {
        for (int i=2;i<=sqrt(b);++i) {
            if (b%i==0) {
                return 0;
            }
        }
        arr[b] = true;
        return 1;
    }

}

bool chk(long long a) {
    long long n = sqrt(a);
    if (n*n == a) {
        if(arr[n]) return 1;
        if (prime(n)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    long long n;
    cin >> n;
    long long a;
    while(n--) {
        cin >> a;
        if(chk(a)) cout << "YES";
        else cout << "NO";
        cout << "\n";
    }
}
