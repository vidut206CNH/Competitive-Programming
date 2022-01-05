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
#define db(x) cerr << "[" << "Line " << __LINE__ << " -- " << (#x) << " : " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 25;
const int MAXN2 = (1LL << 20) + 5;
const int inf = 1e18;

int n,k;
int a[MAXN1][MAXN1];
int dp[MAXN2];


signed main() {
	fast_cin();
	
	cin >> n >> k;
	for(int i=0;i<n;++i) {
		for(int j=0;j<n;++j) {
			cin >> a[i][j];
		}
	}
	memset(dp, 0x3f, sizeof dp);
	dp[(1LL << n) - 1] = 0;
	int ans = inf;
	for(int mask = (1LL << n) - 2; mask > 0; --mask) {
		for(int i=0;i < n;++i) {
			if(!(mask >> i & 1)) {
				for(int j=0;j < n;++j) {
					if(mask >> j & 1) {
						dp[mask] = min(dp[mask], dp[mask^(1LL << i)] + a[i][j]);	
					}
				}
			}
		}
		if((int)__builtin_popcount(mask) == k) ans = min(ans, dp[mask]);
	}	
	
	cout << ans;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}