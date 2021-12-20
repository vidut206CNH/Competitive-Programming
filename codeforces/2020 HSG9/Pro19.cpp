#include<bits/stdc++.h>
#pragma GCC optimize("O1")

using namespace std;

const int nMax = 1e6 + 1;

vector<bool> prime(nMax, 1);

void sieve() {
    prime[0] = 0;
    prime[1] = 0;
    for (int i = 2; i * i <= nMax; ++i) {
        if (prime[i]) {
            for (int j = i * i; j <= nMax; j += i) {
                prime[j] = 0;
            }
        }
    }
}



bool isprime(int n) {
    if (n == 1 || n == 0) return 0;
    if (n % 2 == 0 && n > 2) return 0;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string temp, res = "";
    sieve();
    int n, x; cin >> n;
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (x < nMax && prime[x]) a.push_back(x);
        else if (x >= nMax && isprime(x)) a.push_back(x);
    }
    sort(a.begin(), a.end());
    if (a.size() != 0) {
        int k = a.size() - 1;
        for (int i = k; i >= 0; --i) {
            stringstream ss;
            ss << a[i];
            ss >> temp;
            if ((k - i) % 2 == 0) {
                res = res + temp + ' ';
            }
            else res = temp + ' ' + res;
        }
        cout << res;
    }
    else cout << -1;


}
