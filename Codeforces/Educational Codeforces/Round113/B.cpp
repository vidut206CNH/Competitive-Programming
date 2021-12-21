#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> a(n);
	vector<int> b, c;
	vector< vector<char> > ans(n, vector<char>(n, '+'));
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] == '1') b.push_back(i);
		if (a[i] == '2') c.push_back(i);
	}
	for (int i = 0; i < n; ++i) ans[i][i] = 'X';
	for (int i = 0; i < b.size(); ++i) {
		for (int j = i + 1; j < b.size(); ++j) {
			ans[b[i]][b[j]] = '=';
			ans[b[j]][b[i]] = '=';
		}
		for (int k = 0; k < n; ++k) {
			if (ans[k][b[i]] != '=' && k != b[i]) {
				ans[b[i]][k] = '+';
				ans[k][b[i]] = '-';
			}
		}
	}
	for (int i = 0; i < c.size(); ++i) {
		bool chk = 0;
		for (int j = 0; j < n; ++j) {
			if (ans[c[i]][j] == '+' && !chk) {
				ans[j][c[i]] = '-';
				chk = 1;
			}
			else if (ans[c[i]][j] == '+' && chk == 1 && ans[j][c[i]] == '+') {
				ans[c[i]][j] = '-';
			}
		}
		if (!chk) {
			cout << "NO" << '\n';
			return;
		}
	}
	cout << "YES" << '\n';
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << ans[i][j];
		}
		cout << '\n';
	}


}

int main() {
	int t;
	cin >> t;
	while (t) {
		solve();
		--t;
	}
}