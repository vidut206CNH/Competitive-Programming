/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define gcd(a,b) (__gcd(a,b))
#define lcm(a,b) (a/gcd(a,b)*b)
#define sz(x) (int)(x.size())
#define fast_cin() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define db(x) cerr << "[" << "Line " << __LINE__ << " : " << (#x) << " = " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 505;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n;
int a[MAXN1][MAXN1];
int f[MAXN1][MAXN1];


int get(int x, int y, int u, int v) {
	return f[u][v] - f[x-1][v] - f[u][y - 1] + f[x - 1][y - 1];
}

signed main() {
	fast_cin();
	
	freopen("chiadat.inp", "r", stdin);
	freopen("chiadat.out", "w", stdout);
	
	cin >> n;
	
	for(int i=1;i<=n;++i) {
		for(int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + a[i][j];
		}
	}
	
	int res = 1e9;
	
	for(int i=1;i<=n;++i) {
		for(int j=1; j <= n; ++j) {
			int d1 = get(1, 1, i, j);
			int d2 = get(1, j + 1, i, n);
			int d3 = get(i + 1, 1, n, j);
			int d4 = get(i + 1, j + 1, n, n);
/*			db(d1);
			db(d2);
			db(d3);
			db(d4);
			cerr << '\n';*/
			int d = min({d1, d2, d3, d4});
			int g = max({d1, d2, d3, d4});
			
			res = min(res, g - d);
		}
	}
	
	cout << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}