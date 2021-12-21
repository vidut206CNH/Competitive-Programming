#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1000000007;

int main() {
	ll n, res = 1;
	cin >> n;
	for (ll i = 2; i <= n; ++i) {
		res = (res * i / __gcd(res, i)) % mod;
	}
	cout << res % mod;
}