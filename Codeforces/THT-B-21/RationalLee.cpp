#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


void solve() {
	ll n, k, ans = 0, s1 = 0;
	cin >> n >> k;
	vector<ll> a(n), b(k);
	for (ll i = 0; i < n; ++i) cin >> a[i];
	sort(a.begin(), a.end(), greater<ll>());
	for (ll i = 0; i < k; ++i) {
		cin >> b[i];
	}
	sort(b.begin(), b.end());
	ll i = 0, j = 0, l = n - 1;
	while (b[i] == 1 && i < k) {
		ans += a[j] * 2;
		j++;
		i++;
	}
	sort(b.begin(), b.end(), greater<ll>());
	j += k - i - 1;
	i = 0;
	while (i < k &&  b[i] != 1 ) {
		ans += a[j] + a[l];
		l -= (b[i] - 1);
		j--;
		i++;
	}
	cout << ans << '\n';

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