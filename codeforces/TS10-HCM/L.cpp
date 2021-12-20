#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int m, n, co = 0, cnt1, cnt2, x;
	bool chk = 0;
	cin >> m >> n;
	int a[m][n];
	vector<int> ans;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
			if (a[i][j]) chk = 1;
		}
	}
	while (co < m && chk) {
		int ro = 0;
		while (ro < n) {
			if (a[ro][co] == 1) {
				cnt1 = 1, cnt2 = 1;
				for (int i = ro + 1; i < m; ++i) {
					if (a[i][co] == 0) break;
					cnt1++;
				}
				for (int j = co + 1; j < n; ++j) {
					if (a[ro][j] == 0) break;
					cnt2++;
					for (int l = ro; l <= min(ro + cnt1 - 1, n - 1); ++l) {
						a[l][j] = 0;
					}
				}
				x = cnt1 * cnt2;
				ans.push_back(x);
				ro += cnt1;
			}
			ro++;
		}
		co++;
	}
	if (!chk) {
		return 0;
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); ++i) cout << ans[i] << '\n';
}