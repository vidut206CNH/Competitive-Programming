/*
	link problem:
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a/gcd(a,b))*b

const ll MOD = 1000000007;
const ll nMax = 1e6 + 1;

void solve() {
	int m, n;
	cin  >> m >> n;
	int a[m + 1][n + 1], row[m + 1][n + 1], col[m + 1][n + 1];
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			row[i][j] = row[i][j - 1] + a[i][j];
			col[i][j] = col[i - 1][j] + a[i][j];
		}
	}
	// for (int i = 1; i <= m; ++i) {
	// 	for (int j = 1; j < +n; ++j) {
	// 		sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + a[i][j] - sum[i - 1][j - 1];
	// 	}
	// }
	int ans = -nMax, tmp = 0;
	for (int l = 2; l <= n; ++l) {
		for (int st = 1; st + l - 1 <= n; ++st) {
			for (int r1 = 1; r1 < m; ++r1) {
				for (int r2 = r1 + 1; r2 <= m; ++r2) {
					tmp = (row[r1][st + l - 1] - row[r1][st - 1]) + (row[r2][st + l - 1] - row[r2][st - 1]);
					//cout << tmp << ' ';
					tmp = tmp + (col[r2][st] - col[r1 - 1][st]) + (col[r2][st + l - 1] - col[r1 - 1][st + l - 1]);
					//cout << tmp << ' ';
					tmp = tmp - (a[r1][st] + a[r1][st + l - 1] + a[r2][st] + a[r2][st + l - 1]);
					ans = max(ans, tmp);
					//cout << tmp << '\n';
				}
			}
		}
	}
	cout << ans;
}


int main() {
	fast_cin();
	ll t = 1;
	//cin >> t;
	while (t) {
		solve();
		cout << '\n';
		--t;
	}
	return 0;
}