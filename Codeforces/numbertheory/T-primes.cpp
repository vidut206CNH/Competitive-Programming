#include<bits/stdc++.h>

using namespace std;

void solve() {
	long long a, b;
	cin >> a;
	b = sqrt(a);
	if (b * b == a && b > 1) {
		for (int i = 2; i * i <= b; ++i) {
			if (b % i == 0) {
				cout << "NO" << '\n';
				return;
			}
		}
		cout << "YES" << '\n';
	}
	else cout << "NO" << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	while (n) {
		solve();
		--n;
	}
}