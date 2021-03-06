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
const int MAXN1 = 2e3+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,D;
int a[MAXN1];
int pos[MAXN1];
vector<int> f;
int dp[MAXN1];
int res = 0;

void solve() {
	dp[0] = f[0];
	int lim = 1;
	for(auto x : f) {
		int idx = lower_bound(dp, dp + lim, x) - dp;
		dp[idx] = x;
		if(idx == lim) {
			++lim;
		}
	}
	
	res = max(res, lim);
}


signed main() {
	fast_cin();
	
	cin >> n >> D;
	for(int i = 1; i <= 2*n; ++i) cin >> a[i];
	
	for(int d = 1; d < 2*n; ++d) {
		pos[a[d]] = d;
		f.clear();
		for(int i = d + 1; i <= 2*n; ++i) {
			vector<int> tmp;
			for(int val = max(0LL, a[i] - D); val <= min(2*n, a[i] + D); ++val) {
				if(pos[val]) tmp.push_back(pos[val]); 
			}
			sort(tmp.begin(), tmp.end(), greater<int>());
			for(auto x : tmp) f.push_back(x);
		}
		solve();
		
	}
	
	cout << res;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}