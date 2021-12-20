#include<bits/stdc++.h>

using namespace std;


int main() {
	int n, m, cnt = 0;
	cin >> n >> m;
	char a[n][m];
	vector< vector<int> > out(n, vector<int>(m, 1));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
			if (a[i][j] == 'N' && i > 0) {
				out[i - 1][j] += out[i][j];
			}
			if (a[i][j] == 'S' && i < n - 1) {
				out[i + 1][j] += out[i][j];
			}
			if (a[i][j] == 'W' && j > 0) {
				out[i][j - 1] += out[i][j];
			}
			if (a[i][j] == 'E' && j < m - 1) {
				out[i][j + 1] += out[i][j];
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i == 0 && a[i][j] == 'N') {
				cnt += out[i][j];
			}
			if (i == n - 1 && a[i][j] == 'S') {
				cnt += out[i][j];
			}
			if (j == 0 && a[i][j] == 'W') {
				cnt += out[i][j];
			}
			if (j == m - 1 && a[i][j] == 'E') {
				cnt += out[i][j];
			}
		}
	}
	cout << out[3][4];

}