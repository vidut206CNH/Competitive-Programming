#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	string s;
	cin >> s;
	ll cnt1 = 0, cnt0 = 0;
	for (ll i = 0; i < s.size(); ++i) {
		if (s[i] == '0' && (s[i - 1] == '1' || i == 0)) {
			cnt0++;
		}
	}
	if (cnt0 <= 2) {
		cout << cnt0 << '\n';
		return ;
	}
	cout << 2 << '\n';

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