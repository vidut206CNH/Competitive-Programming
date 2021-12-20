#include<bits/stdc++.h>

using namespace std;

void solve() {
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		if (((int)s[i] - i) % 2 == 0) {
			cout << "NO" << '\n';
			return;
		}
	}
	cout << "YES" << '\n';
}


int main() {
	int t;
	cin >> t;
	while (t) {
		solve();
		--t;
	}
}