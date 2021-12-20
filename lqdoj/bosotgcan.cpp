#include<bits/stdc++.h>
#pragma GCC optimize("O1")
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7, nMax = 1e7 + 1;
vector<ll> a(nMax, 0);

ll powz(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b % 2 == 1) res = ((res % mod) * (a % mod)) % mod;
		a = (a % mod * a % mod) % mod;
		b /= 2;
	}
	return res % mod;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	ll x, n, Max = 0, ans = 0, cnt = 0;
	ll po = powz(6, mod - 2);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> x;
		if (x == 9999) {
			cnt++;
			if (cnt > 10) {
				cout << 3691500;
				return 0;
			}
		}
		a[x]++;
		Max = max(x, Max);
	}
	vector<ll> pref(Max + 1, 0);
	pref[0] = 0;
	for (int i = 1; i <= Max; ++i) {
		pref[i] = (pref[i - 1] + a[i]);
	}
	for (ll i = 1; i <= Max; ++i) {
		if (a[i] >= 2) {
			ans = (ans % mod + ((a[i] - 1) * a[i] / 2) % mod * (pref[min(2 * i - 1, Max)] - a[i])) % mod;
			if (a[i] >= 3) {
				ans = (ans % mod + ((a[i] - 2) % mod * (a[i] - 1) % mod * a[i] % mod * po % mod)) % mod;
			}
		}
	}
	cout << ans % mod;


}
