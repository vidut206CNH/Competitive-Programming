#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	ll x, ans = 0, Max = -1e9, Min = 1e9;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> x;
		if (i % 2 != 0) {
			ans += x;
			Min = min(Min, x);
		}
		else {
			ans -= x;
			Max = max(Max, x);
		}
	}
	cout << ans + 2 * (Max - Min);
}
