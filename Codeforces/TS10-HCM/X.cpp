#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int m, n;
	cin >> m >> n;
	int pref[m + 1][n + 1];
	for (int i = 1; i <= m; ++i) {
		int sum = 0;
		pref[i][0] = 0;
		for (int j = 1; j <= n; ++j) {
			int x;
			cin >> x;
			sum += x;
			pref[i][j] = sum;
		}
	}
	int ans = 0, ar, ac;
	for (int i = 1; i <= m - 2; ++i) {
		for (int j = 1; j <= n - 2; ++j) {
			int sum = (pref[i][j + 2] - pref[i][j - 1]) + (pref[i + 1][j + 2] - pref[i + 1][j - 1]) + (pref[i + 2][j + 2] - pref[i + 2][j - 1]);
			if (sum > ans) {
				ans = sum;
				ar = i;
				ac = j;
			}
		}
	}
	cout << ans << '\n' << ar << ' ' << ac;
}