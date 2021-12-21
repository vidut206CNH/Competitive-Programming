#include<bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, k, l;
	long long res = 0;
	cin >> n;
	vector<int> a(n + 1, 0);
	vector < vector<int> > pref(n + 1, vector<int>(2, 0)), suff(n + 1, vector<int>(2, 0));
	pref[0][0] = -1e6;
	pref[0][1] = 1e6;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		pref[i][0] = max(pref[i - 1][0], a[i]);
		pref[i][1] = min(pref[i - 1][1], a[i]);
	}
	suff[n][0] = a[n];
	suff[n][1] = a[n];
	for (int i = n - 1; i > 0; --i) {
		suff[i][0] = max(suff[i + 1][0], a[i]);
		suff[i][1] = min(suff[i + 1][1], a[i]);
	}
	for (int i = 2; i < n; ++i) {
		if (abs(pref[i - 1][0] - suff[i + 1][1]) > abs(pref[i - 1][1] - suff[i + 1][0])) {
			k = pref[i - 1][0];
			l = suff[i + 1][1];
		}
		else {
			k = pref[i - 1][1];
			l = suff[i + 1][0];
		}
		res = max(res, 1LL * (k - a[i]) * (a[i] - l));
	}
	cout << res;


}