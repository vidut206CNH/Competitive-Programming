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
const int MAXN1 = 1e3 + 5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,k;
int a[MAXN1];
int dp[MAXN1][55];

signed main() {
	fast_cin();
	
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	
	memset(dp, -1, sizeof dp);
	dp[0][0] = 0;
	
	for(int i = 0; i < n; ++i) {
		for(int cur = 0; cur < k; ++cur) {
			int val = dp[i][cur];
			if(val == -1) continue;
			// choose a[i + 1]
			dp[i + 1][(cur + a[i + 1])%k] = max(dp[i + 1][(cur + a[i + 1])%k], dp[i][cur] + 1);
			// not choose
			dp[i + 1][cur] = max(dp[i + 1][cur], dp[i][cur]);
		}
	}
	
	cout << dp[n][0];
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}