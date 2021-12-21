#include<bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, x, res = 0;
	cin >> n;
	vector<int> pref(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> x;
		if (i > 1) {
			res = max(res, x - pref[i - 1]);
			pref[i] = min(pref[i - 1], x);
		}
		else pref[i] = x;
	}
	cout << res;
}