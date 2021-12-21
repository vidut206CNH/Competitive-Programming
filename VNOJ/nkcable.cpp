/*
	link problem:
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;



#define int long long
#define fi first
#define se second
#define fast_cin() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 2e18

typedef pair<int, int> pii;

const int MOD = 1e9 + 7;
const int MAXX = 2e9;
const int MINN = -2e9;
const int nMax = 1e6 + 5;

bool flag = 0;
int n, a[25005], t1, t2, ans;
int f1[25005], f2[25005];

void solve() {
	cin >> n;
	for (int i = 1; i < n; ++i) {
		cin >> a[i];
	}
	f1[2] = a[1];
	f2[2] = a[1] + a[2];
	for (int i = 3; i <= n; ++i) {
		f1[i] = min(f2[i - 1], f1[i - 1] + a[i - 1]);
		if (i < n) f2[i] = min(f1[i - 1], f2[i - 1]) + a[i];
		else f2[i] = min(f2[i - 1], f1[i]);
		//cout << f1[i] << ' ' << f2[i] << '\n';
	}
	cout << min(f1[n], f2[n]);

}


int32_t main() {
	fast_cin();
	int t = 1;
	//cin >> t;
	while (t) {
		solve();
		cout << '\n';
		--t;
	}
	return 0;
}