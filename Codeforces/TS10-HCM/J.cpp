#include<bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int m, n;
	cin >> m >> n;
	int a[m][n], ans = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
			if (a[i][j]) {
				ans += 4 - 2 * (a[i][j - 1] && j > 0) - 2 * (a[i - 1][j] && i > 0);
			}
		}
	}
	cout << ans;
}