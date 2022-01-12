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
const int MAXN2 = 1e5+5;
const int inf = 1e18;

int n,l,k;
int p[MAXN1];
int d[MAXN1];
vector< vector<int> > dp(MAXN1, vector<int>(MAXN1, inf));

signed main() {
	fast_cin();
	
	cin >> n >> l >> k;

	for(int i=1;i<=n;++i) {
		cin >> p[i];
	}
	for(int i=1;i<=n;++i) cin >> d[i];
	
	for(int i=0;i<=k;++i) dp[1][i] = 0;
	
	int res = inf;
	for(int i=2;i<=n;++i) {
		for(int u = 0;u <= k;++u) {
			for(int pos = i-1;pos >= max(1LL,i-u-1);--pos) {
				dp[i][u] = min( dp[i][u], dp[pos][u - (i-pos - 1)] + d[pos]*(p[i] - p[pos]));
/*				db(dp[i][u]);
				db(i);
				db(u);
				db(pos);*/
				if(n - i + u <= k) res = min(res, dp[i][u] + d[i]*(l - p[i]));
/*				db(res);
				cerr << "\n";*/
			}
		}	
	}
	if(k == n-1) res = min(res, d[1]*l);
	
	cout << res;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}