#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	ll n, s;
	cin >> n >> s;
	cout << s / (n - n / 2 + (n % 2 == 0)) << '\n';

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