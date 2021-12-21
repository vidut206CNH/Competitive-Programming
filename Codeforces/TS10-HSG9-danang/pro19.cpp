#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll powz(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res *= a;
		a *= a;
		b /= 2;
	}
	return res;
}


int main() {
	ll n, cnt = 0, res = 1;
	cin >> n;
	while (n % 2 == 0) {
		cnt++;
		n /= 2;
	}
	res *= powz(2, cnt / 2);
	cnt = 0;
	for (ll i = 3; i * i <= n; i += 2) {
		if (n % i == 0) {
			while (n % i == 0) {
				cnt++;
				n /= i;
			}
			res *= powz(i, cnt / 2);
			cnt = 0;
		}
	}
	cout << res;
}