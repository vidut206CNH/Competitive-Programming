#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll nMax = 1e6 + 1;
ll a[nMax];

void solve() {
	int m, n;
	ll  x, res = 1;
	cin >> n >> m;
	memset(a, 0, nMax);
	for (int i = 1; i <= n; ++i) {
		cin >> x;
		Max = max(Max, x);
		while (x % 2 == 0 && x > 1) {
			a[2]++;
			x /= 2;
		}
		for (ll i = 3; i * i <= x; i += 2) {
			while (x % i == 0 && x > 1) {
				a[i]++;
				x /= i;
			}
		}
		if (x > 1) {
			if (x < nMax) a[x]++;
			else res *= x;
		}
	}
	for (int i = 0; i < m; ++i) {
		cin >> x;
		while (x % 2 == 0 && x > 1) {
			a[2]--;
			x /= 2;
		}
		for (ll i = 3; i * i <= x; i += 2) {
			while (x % i == 0 && x > 1) {
				a[i]--;
				x /= i;
			}
		}
		if (x > 1) {
			if (x < nMax) a[x]--;
			else {
				if (res % x != 0) {
					cout << "NO";
					return;
				}
				else res /= x;
			}
		}
	}
	if (a[2] != 0 || res != 1) {
		cout << "NO" << '\n';
		return;
	}
	for (ll i = 3; i < nMax; i += 2) {
		if (a[i] != 0) {
			cout << "NO" << '\n';
			return;
		}
	}
	cout << "YES" << '\n';


}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t) {
		solve();
		--t;
	}
}