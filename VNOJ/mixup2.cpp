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
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,k;
int a[20];
int dp[(1 << 16) + 5][17];

signed main() {
	fast_cin();
	
	cin >> n >> k;	 
	for(int i = 0; i < n; ++i) cin >> a[i];
	
	
	// DP
	for(int i = 0; i < n; ++i) {
		dp[(1 << i)][i] = 1;
	}
	for(int mask = 1; mask < (1 << n); ++mask) {
		vector<int> on, off;
		for(int i = 0; i < n; ++i) {
			if((mask >> i) & 1) on.push_back(i);
			else off.push_back(i); 
		}
		
		for(auto last : on) {
			for(auto next : off) {
				if(abs(a[last] - a[next]) > k) {
					dp[mask | (1 << next)][next] += dp[mask][last];
				}
			}
		}

	}
	
	// results
	int res = 0;
	for(int i = 0; i < n; ++i) res += dp[(1 << n) - 1][i];
	
	cout << res;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}