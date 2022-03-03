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
const int MAXN1 = 5e3+5;
const int MAXN2 = 1e5+5;
const int inf = 1e18;

int n,m;
int a[MAXN1];
int dp[MAXN1];	
int best[MAXN2];

signed main() {
	fast_cin();
	
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1; i <= m; ++i) cin >> best[i];
	for(int i = m - 1; i >= 1; --i) best[i] = min(best[i], best[i + 1]);
	
	sort(a + 1, a + n + 1);
	// DP
	for(int i = 1; i <= n; ++i) {
		dp[i] = inf;
		for(int j = i; j >= 1; --j) {
			dp[i] = min(dp[i], dp[j - 1] + best[a[i] - a[j] + 1]);
		}
	}
	
	cout << dp[n];
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}