#include<bits/stdc++.h>

using namespace std;

typedef long long ll;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n + 1), b(m + 1), pref(m + 1, 0);
	a[0] = b[0] = 0;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= m; ++i) cin >> b[i];
	sort(b.begin(), b.end());
	for (int i = 1; i <= m; ++i) pref[i] = pref[i - 1] + b[i];
	for (int i = 1; i <= n; ++i) {
		int k = 0;
		auto it = lower_bound(b.begin(), b.end(), a[i]);
		int j = (it - b.begin());
		if (b[j] > a[i])  --j;
		a[i] += pref[j] - pref[k];
		k = j;
		it = lower_bound(b.begin(), b.end(), a[i]);
		j = (it - b.begin());
		if (j > m) a[i] += pref[m] - pref[k];
		else {
			if (b[j] > a[i]) --j;
			while (a[i] >= b[j] &&  j <= m && j > k) {
				a[i] += pref[j] - pref[k];
				k = j;
				it = lower_bound(b.begin(), b.end(), a[i]);
				j = (it - b.begin());
				if (j > m) {
					a[i] += pref[m] - pref[k];
					break;
				}
				if (b[j] > a[i]) --j;
			}
		}
	}
	for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
}