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
const int MAXN1 = 1e3+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int dp_right[2][MAXN1][MAXN1];
int dp_left[2][MAXN1][MAXN1];
int a[MAXN1][MAXN1];
int m,n;

signed main() {
	fast_cin();
	
	cin >> m >> n;
	
	for(int i=1;i<=m;++i) {
		for(int j=1;j<=n;++j) {
			cin >> a[i][j];
		}
	}
	
	//dp_right
	
	for(int i=1;i<=m;++i) {
		for(int j=1;j<=n;++j) {
			dp_right[0][i][j] = max(dp_right[0][i-1][j], dp_right[0][i][j-1]) + a[i][j];
/*			db(i);
			db(j);
			cerr << dp_right[0][i][j] << "\n";*/
		}
	}
	//cerr << "\n";
	
	for(int i=m;i>=1;--i) {
		for(int j=n;j>=1;--j) {
			dp_right[1][i][j] = max(dp_right[1][i + 1][j], dp_right[1][i][j + 1]) + a[i][j];
			
/*			db(i);
			db(j);
			cerr << dp_right[1][i][j] << "\n";*/
		}
	}
	//cerr << "\n";
	//dp_left
	
	for(int i=m;i>=1;--i) {
		for(int j=1;j<=n;++j) {
			dp_left[0][i][j] = max(dp_left[0][i + 1][j], dp_left[0][i][j-1]) + a[i][j];
		}
	}
	
	for(int i = 1;i <= m; ++i) {
		for(int j = n; j >= 1; --j) {
			dp_left[1][i][j] = max(dp_left[1][i - 1][j], dp_left[1][i][j + 1]) + a[i][j];
		}
	}
	
	int res = 0;
	for(int i=1;i<=m;++i) {
		for(int j=1;j<=n;++j) {
			int best1 = max(dp_right[0][i - 1][j], dp_right[0][i][j - 1]) + max(dp_right[1][i + 1][j], dp_right[1][i][j + 1]);
			int best2 = max(dp_left[0][i + 1][j], dp_left[0][i][j - 1]) + max(dp_left[1][i - 1][j], dp_left[1][i][j + 1]);
/*			db(i);
			db(j);
			db(best1);
			db(best2);
			cerr << "\n";*/
			res = max(res, best1 + best2);
		}
	}
	
	cout << res;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}