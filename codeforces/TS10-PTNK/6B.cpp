#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ll n, x, y, res, temp;
	string s; char c;
	cin >> n >> x >> y;
	vector < vector<ll> > a(n + 1, vector<ll>(n + 1, 0));
	//Tao mang a[n+1][n+1]
	a[1][1] = 1;
	a[1][2] = 2;
	for (ll i = 3; i <= n; i += 2) {
		a[1][i] = a[1][i - 1] + 2 * (i - 1);
		if (i < n) a[1][i + 1] = a[1][i] + 1;
	}
	for (ll i = 2; i <= n; i += 2) {
		a[i][n] = a[i - 1][n] + 2 * (n - i + 1);
		if (i < n) a[i + 1][n] = a[i][n] + 1;
	}
	for (ll i = 2; i <= n; ++i) {
		for (ll j = 1; j < n; ++j) {
			if ((i + j) % 2 == 0) {
				a[i][j] = a[i - 1][j + 1] - 1;
			}
			else a[i][j] = a[i - 1][j + 1] + 1;
		}
	}
	//Solve
	res = a[x][y];
	while (cin >> c) {
		a[x][y] = 0;
		if (c == 'S') res += a[++x][y];
		if (c == 'N') res += a[--x][y];
		if (c == 'W') res += a[x][--y];
		if (c == 'E') res += a[x][++y];
	}
	cout << res;
}