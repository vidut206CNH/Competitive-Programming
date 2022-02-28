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
const int MAXN1 = 2e4+5;
const int MAXN2 = 1e3+5;
const int inf = 1e18;

int n;
int a[MAXN2];
int dp[MAXN1];

signed main() {
	fast_cin();
	
	cin >> n;
	int res = 0;
	memset(dp, -1, sizeof dp);
	
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		
		for(int  mask = 0; mask < MAXN2; ++mask) {
			if(dp[mask] == -1) continue;
			res = max(res, a[i] + dp[mask] - (a[i]^mask));
		}
		
		for(int j = 1; j < i; ++j) {
			dp[a[i]^a[j]] = max(dp[a[i]^a[j]], a[i] + a[j]);
		}
	}
	
	cout << res;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}