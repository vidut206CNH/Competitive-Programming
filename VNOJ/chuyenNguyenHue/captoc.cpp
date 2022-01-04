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
#define INF 2e18
#define db(x) cerr << "[" << "Line " << __LINE__ << " -- " << (#x) << " : " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 1e2+5;
const int MAXN2 = 1e6+5;

int n,m;
int dp	[MAXN1][MAXN1];
int f[MAXN1][MAXN1];
int a[MAXN1][MAXN1];

signed main() {
	fast_cin();
	
	cin >> n >> m;
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=m;++j) {
			cin >> a[i][j];
		}
	}
	
	dp[0][0] = 0;
	
	for(int i=1;i<=n;++i) {
		dp[i][0] = 0;
		for(int w=1;w <= m;++w) {
			dp[i][w] = dp[i-1][w];
			for(int pos = 0;pos <= w;++pos) {
				dp[i][w] = max(dp[i][w], dp[i-1][w - pos] + a[i][pos]);
			}
		}
	}
	
	cout << dp[n][m];
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}