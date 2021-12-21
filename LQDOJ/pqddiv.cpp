#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll nMax = 1e6 + 1;

int main() {
	ll n, sum = 0, x;
	cin >> n;
	vector<ll> a(nMax, 0);
	a[0] = 1;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		sum += x;
		for (ll j = x; j <= sum; j++) {
			a[j] += a[j - x];
		}
	}
	for (ll i = sum / 2; i > 0; --i) {
		if (a[i]) {
			cout << sum - 2 * i << ' ' << a[i];
			return 0;
		}
	}

}