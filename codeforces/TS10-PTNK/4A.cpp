#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll nMax = 1e6 + 1, nMax1 = 2e7 + 1;
vector<bool> a(nMax1, 1);


void sieve() {
	a[0] = a[1] = 0;
	for (ll i = 2; i * i < nMax; ++i) {
		if (a[i]) {
			for (ll j = i * i; j < nMax; j += i) {
				a[j] = 0;
			}
		}
	}
}

bool chk(ll n) {
	if (n % 2 == 0) return 0;
	for (ll i = 3; i * i <= n; i += 2) {
		if (n % i == 0) return 0;
	}
	return 1;
}
void solve() {
	ll n;
	cin >> n;
	if ((n < nMax && a[n]) || (n >= nMax && !(a[n] = (a[n] && !chk(n))))) {
		int j = 2;
		while (n + j < nMax1) {
			bool chk1 = (n - j < nMax) ? (a[n - j]) : !(a[n - j] = (a[n - j] && !chk(n - j)));
			bool chk2 = (n + j < nMax) ? (a[n + j]) : !(a[n + j] = (a[n + j] && !chk(n + j)));
			if (chk1 || chk2) {
				if (chk1 && chk2) cout << "YES";
				else cout << "NO";
				return;
			}
			j += 2;
		}
	}
	else cout << "NO";
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	sieve();
	while (t) {
		solve();
		cout << '\n';
		--t;
	}
}