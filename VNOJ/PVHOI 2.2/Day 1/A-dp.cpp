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
const int MAXN1 = 2e3 + 5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int a[MAXN1];
int n,m;


signed main() {
	fast_cin();
	
	
	cin >> n >> m;
	for(int i=1;i<=n;++i) {
		cin >> a[i];
	}
	
	vector< vector<int> > dp(MAXN1, vector<int>(MAXN1, inf));
	vector<int> best(MAXN1,inf);
	
	for(int i=0;i<MAXN1;++i) dp[i][0] = 0;
	
	for(int i=n;i>=1;--i) {
		for(int j=1;j<=(n - i + 1); ++j) {
			dp[i][j] = min(dp[i+1][j-1] - a[i], dp[i+1][j]);
			dp[i][j] = max(dp[i][j], 0LL);
			
			int val = dp[i][j];
/*			db(i);
			db(j);
			db(val);
			cerr << "\n";*/
			if(i==1) best[j] = dp[i][j];
		}
	}
	
	
/*	
	for(int i=1;i<=n;++i) {
		db(best[i]);
	}*/
	
	for(int i=1;i<=m;++i) {
		int val;
		cin >> val;
		int l=1,r=n,res = 0;
		while(l <= r) {
			int mid = (l+r) >> 1;
			if(best[mid] <= val) {
				l = mid + 1;
				res = mid;
			} else r = mid - 1;
		}
		
		cout << res << " ";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}