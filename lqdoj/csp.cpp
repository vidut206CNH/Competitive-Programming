#include<bits/stdc++.h>

using namespace std;

const long long nMax = 1e7 + 1;

typedef long long ll;

ll a[nMax];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, m, x, Max = 0, ans = 0;
	cin >> n >> m;
	for	(ll i = 0; i < n; ++i) {
		cin >> x;
		a[x]++;
		Max = max(Max, x);
	}
	ll pref[m + 1];
	pref[0] = 0;
	for	(ll i = 1; i < m; ++i) {
		pref[i] = pref[i - 1] + a[i];
	}
	for	(ll i = 1; i <= m / 2; ++i) {
		if (a[i] != 0) {
			ans += (pref[m - i] - pref[i]) * a[i];
			if (a[i] > 1) {
				ans += (a[i] - 1) * a[i] / 2;
			}
		}
	}
	cout << ans;
}