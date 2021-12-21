#include<bits/stdc++.h>

using namespace std;


void solve() {
	int n, cnt = 0;
	cin >> n;
	// cin.ignore();
	string s = "";
	vector<char> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		s += a[i];
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; ++i) {
		if (a[i] != s[i]) cnt++;
	}
	cout << cnt << '\n';
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