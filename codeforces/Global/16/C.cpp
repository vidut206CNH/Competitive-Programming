#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	ll n;
	ll ans = 0;
	cin >> n;
	string s1, s2, res = "";
	cin >> s1 >> s2;
	for (ll i = 0; i < n; ++i) {
		if (s1[i] + s2[i] - 2 * '0' == 1) {
			res += '2';
		}
		else if (s1[i] + s2[i] - 2 * '0' == 2) {
			res += '0';
		}
		else res += '1';
	}
	ll i = 0;
	while (i < n) {
		if (res[i] == '2') {
			ans += 2;
			++i;
		}
		else {
			if (res[i] + res[i + 1] - 2 * '0' == 1 && i < n - 1) {
				ans += 2;
				i++;
			}
			else if (res[i] == '1') {
				ans++;
			}
			i++;
		}
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