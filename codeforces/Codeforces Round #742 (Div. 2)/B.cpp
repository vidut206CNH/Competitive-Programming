#include<bits/stdc++.h>

using namespace std;

void solve() {
	int a, b, res = 0;
	cin >> a >> b;
	for (int i = 0; i < a; ++i) {
		res ^= i;
	}
	cout << (res | b) << ' ' << res << '\n';

}

int main() {
	int t;
	cin >> t;
	while (t) {
		solve();
		--t;
	}
}